#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template<class Info, class Tag>
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
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
            apply(p, v);
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
};

constexpr int inf = 1e9;

struct Tag {
    int add = 0;
    void apply(const Tag &t) {
        add += t.add;
    }
};
struct Info {
    int max = 0;
    void apply(const Tag &t) {
        max += t.add;
    }
};
constexpr Info operator+(const Info &a, const Info &b) {
    return {std::max(a.max, b.max)};
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (is_sorted(a.begin(), a.end(), greater())) {
        cout << 1 << "\n";
        return;
    }

    vector<int> l, r;
    for (int i = 0; i < n; i++) {
        if (l.empty() or a[i] < a[l.back()]) {
            l.push_back(i);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (r.empty() or a[i] > a[r.back()]) {
            r.push_back(i);
        }
    }
    reverse(r.begin(), r.end());

    vector<array<int, 4>> events;
    for (int i = 0; i < n; i++) {
        int xl = upper_bound(l.begin(), l.end(), i, 
            [&](int i, int j) {
                return a[i] > a[j];
            }) - l.begin();
        int xr = lower_bound(l.begin(), l.end(), i) - l.begin();
        int yl = upper_bound(r.begin(), r.end(), i) - r.begin();
        int yr = lower_bound(r.begin(), r.end(), i,
            [&](int i, int j) {
                return a[i] > a[j];
            }) - r.begin();
        
        if (xl < xr and yl < yr) {
            events.push_back({xl, 1, yl, yr});
            events.push_back({xr, -1, yl, yr});
        }
    }
    ranges::sort(events);

    int ans = 2;

    LazySegmentTree<Info, Tag> seg(n);
    for (auto [_, t, l, r] : events) {
        seg.rangeApply(l, r, {t});
        ans = max(ans, 2 + seg.rangeQuery(0, n).max);
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}
