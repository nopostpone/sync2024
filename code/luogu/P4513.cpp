#include <bits/stdc++.h>
using ll = long long;

constexpr ll inf = 1e18;

template <class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template <class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    template <class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
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
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
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
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};
struct Info {
    ll sum = -inf;
    ll pre = -inf;
    ll suf = -inf;
    ll res = -inf;
    int act = 0;
};
Info operator+(Info a, Info b) {
    if (a.act == 0) {
        return b;
    }
    if (b.act == 0) {
        return a;
    }
    Info c;
    c.act = a.act + b.act;
    c.sum = a.sum + b.sum;
    c.res = std::max({a.res, b.res, a.suf + b.pre});
    c.pre = std::max(a.pre, a.sum + b.pre);
    c.suf = std::max(b.suf, b.sum + a.suf);
    return c;
}

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        init[i].sum = init[i].pre = init[i].suf = init[i].res = a;
        init[i].act = 1;
    }

    SegmentTree<Info> l(init);

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1) {
            x--, y--;
            if (x > y) {
                swap(x, y);
            }

            cout << l.rangeQuery(x, y + 1).res << "\n";
        } else {
            x--;

            Info t;
            t.act = 1;
            t.res = t.pre = t.sum = t.suf = y;
            l.modify(x, t);
        }
    }

   

    return 0;
}