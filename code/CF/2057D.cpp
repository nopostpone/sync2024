#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(vector<Info>(n_, v_));
    }
    template <class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    template <class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());

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
    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

constexpr int inf = 1e9;
struct Info {
    int maxl;
    int maxr;
    int minl;
    int minr;
    int ans;
    Info(int x = 0, int i = -inf)
        : maxl(x + i), maxr(x - i), minl(x - i), minr(x + i), ans(0) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.maxl = max(a.maxl, b.maxl);
    c.maxr = max(a.maxr, b.maxr);
    c.minl = min(a.minl, b.minl);
    c.minr = min(a.minr, b.minr);
    c.ans = max({a.ans, b.ans, a.maxl - b.minr, b.maxr - a.minl});
    return c;
}

using L = SegmentTree<Info>;

void solve() {
    int n, q;
    cin >> n >> q;

    L seg(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        seg.modify(i, Info(x, i));
    }

    cout << seg.rangeQuery(0, n).ans << "\n";

    while (q--) {
        int p, x;
        cin >> p >> x;
        p--;
        seg.modify(p, Info(x, p));
        cout << seg.rangeQuery(0, n).ans << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}