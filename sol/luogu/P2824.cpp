#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class Info, class Tag>
struct LazySegmentTree {
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
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

struct Tag {
    int isGreater = -1;
    void apply(const Tag &t) {
        if (t.isGreater == -1) {
            return;
        }
        isGreater = t.isGreater;
    }
};

struct Info {
    int cnt = 0;
    int act = 0;
    void apply(const Tag &t) {
        if (t.isGreater == -1) {
            return;
        }
        cnt = act * t.isGreater;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {a.cnt + b.cnt, a.act + b.act};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<array<int, 3>> q(m);
    for (int i = 0; i < m; i++) {
        for (int j : {0, 1, 2}) {
            cin >> q[i][j];
        }
        q[i][1]--;
        q[i][2]--;
    }
    int id;
    cin >> id;
    id--;

    LazySegmentTree<Info, Tag> l(n);

    auto check = [&](int x) {
        for (int i = 0; i < n; i++) {
            l.modify(i, Info{a[i] >= x, 1});
        }
        for (auto [op, x, y] : q) {
            int t = l.rangeQuery(x, y + 1).cnt;
            if (op == 0) {
                t = y - x + 1 - t;
                l.rangeApply(x, x + t, {0});
                l.rangeApply(x + t, y + 1, {1});
            } else {
                l.rangeApply(x, x + t, {1});
                l.rangeApply(x + t, y + 1, {0});
            }
        }
        return l.rangeQuery(id, id + 1).cnt;
    };

    int lo = 1, hi = n;
    int ans;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << ans << endl;

    return 0;
}