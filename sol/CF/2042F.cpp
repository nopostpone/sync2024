#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
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

constexpr i64 inf = 1e18;

template <typename T>
T Max(T a) {
    return a;
}
template <typename T, typename... Args>
T Max(T a, Args... args) {
    T b = Max(args...);
    return std::max(a, b);
}

struct Info {
    i64 ans1 = -inf;
    i64 ans2 = -inf;

    i64 l1 = -inf;
    i64 l2 = -inf;

    i64 r1 = -inf;
    i64 r2 = -inf;

    i64 sum = 0;
    i64 mid = -inf;

    Info() {}
    Info(i64 a, i64 b) {
        ans1 = a + 2 * b;
        l1 = a + b;
        r1 = a + b;
        sum = a;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;

    c.ans2 = Max(b.ans2, a.l1 + b.r2, a.ans1 + b.ans1, a.l2 + b.r1, a.ans2);
    c.ans1 = Max(b.ans1, a.l1 + b.r1, a.ans1);

    c.l1 = Max(b.l1, a.l1 + b.sum);
    c.l2 = Max(b.l2, a.l1 + b.mid, a.ans1 + b.l1, a.l2 + b.sum);

    c.r1 = Max(b.r1 + a.sum, a.r1);
    c.r2 = Max(b.r2 + a.sum, b.ans1 + a.r1, b.r1 + a.mid, a.r2);

    c.sum = a.sum + b.sum;
    c.mid = Max(b.mid + a.sum, a.r1 + b.l1, a.mid + b.sum);

    return c;
}

using L = SegmentTree<Info>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[i] = Info(a[i], b[i]);
    }
    L seg(init);

    int q;
    for (cin >> q; q--;) {
        int o, x, y;
        cin >> o >> x >> y;
        x--;

        if (o == 1) {
            a[x] = y;
            seg.modify(x, Info(a[x], b[x]));
        } else if (o == 2) {
            b[x] = y;
            seg.modify(x, Info(a[x], b[x]));
        } else {
            cout << seg.rangeQuery(x, y).ans2 << "\n";
        }
    }

    return 0;
}