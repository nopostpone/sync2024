// todo : cf1804_g
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = {}) { init(n_, v_); }
    LazySegmentTree(vector<Info> a) { init(a); }

    void init(int n_, Info v_) {
        init(vector<Info>(n_, v_));
    }
    void init(vector<Info> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), {});
        tag.assign(4 << __lg(n), {});

        auto build = [&](auto self, int p, int l, int r) -> void {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void Apply(int p, const Tag &v) {
        info[p].Apply(v);
        tag[p].Apply(v);
    }
    void push(int p) {
        Apply(2 * p, tag[p]);
        Apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            Apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    void half(int p, int l, int r) {
        if (info[p].act == 0) {
            return;
        }
        if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
            Apply(p, {-(info[p].min + 1) / 2});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        half(p * 2, l, m);
        half(p * 2 + 1, m, r);
        pull(p);
    }
    void half() {
        return half(1, 0, n);
    }
};

constexpr i64 inf = 1e18;
struct Tag {
    i64 add = 0;
    void Apply(const Tag &t) {
        add += t.add;
    }
};
struct Info {
    i64 min = inf;
    i64 max = -inf;
    i64 sum = 0;
    i64 act = 0;

    void Apply(const Tag &t) {
        min += t.add;
        max += t.add;
        sum += act * t.add;
    }
};
constexpr Info operator+(const Info &a, const Info &b) {
    Info c;
    c.min = std::min(a.min, b.min);
    c.max = std::max(a.max, b.max);
    c.sum = a.sum + b.sum;
    c.act = a.act + b.act;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;

    vector<array<int, 3>> events;
    for (int i = 0; i < n; i++) {
        int s, f, d;
        cin >> s >> f >> d;
        s--;
        events.push_back({s, i, d});
        events.push_back({f, i, 0});
    }
    ranges::sort(events);

    LazySegmentTree<Info, Tag> seg(n);
    int cur = 0;
    i64 ans = 0;

    for (auto [t, i, d] : events) {
        Info last = {-1, -1, -1, -1};
        i64 lastc = -1;
        i64 lastans = -1;

        while (cur < t) {
            Info now = seg.rangeQuery(0, n);
            if (now.act == 0) {
                cur = t;
                break;
            }

            if (now.min == last.min and
                now.max == last.max and
                now.sum == last.sum and
                now.max - now.min <= 1) {

                i64 dt = cur - lastc;
                i64 dans = ans - lastans;
                i64 phase = (t - cur) / dt;

                cur += phase * dt;
                ans += phase * dans;
            }
            last = now;
            lastc = cur;
            lastans = ans;

            i64 u = (b - now.sum + now.act) / now.act;
            u = min<i64>(u, t - cur);
            u = max<i64>(u, 0);

            cur += u;
            ans += (now.sum + now.sum + now.act * (u - 1)) * u / 2;

            seg.rangeApply(0, n, {u});
            if (t == cur) {
                break;
            }

            cur++;
            seg.half();
        }
        if (d != 0) {
            seg.modify(i, {d, d, d, 1});
        } else {
            seg.modify(i, Info());
        }
    }
    cout << ans << "\n";

    return 0;
}