#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

constexpr int inf = 1e9 + 1;

struct Info {
    int mx = -inf;
    int mn = inf;
};

Info operator+(const Info &a, const Info &b) {
    return Info{max(a.mx, b.mx), min(a.mn, b.mn)};
}

using L = SegmentTree<Info>;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            s.insert(i);
        }
    }

    L seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(i, {a[i], a[i]});
    }

    auto work = [&]() {
        if (s.empty()) {
            cout << -1 << " " << -1 << "\n";
            return;
        }

        int l = *s.begin() + 1;
        int suf = seg.rangeQuery(l, n).mn;
        l = seg.findFirst(0, n, [&](auto f) { return f.mx > suf; });

        int r = *s.rbegin() + 1;
        int pre = seg.rangeQuery(0, r).mx;
        r = seg.findLast(0, n, [&](auto f) { return f.mn < pre; }) + 1;

        cout << l + 1 << " " << r << "\n";
    };
    work();

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;

        s.erase(x - 1);
        s.erase(x);

        a[x] = y;
        if (x > 0 and a[x - 1] > a[x]) {
            s.insert(x - 1);
        }
        if (x + 1 < n and a[x] > a[x + 1]) {
            s.insert(x);
        }
        seg.modify(x, {y, y});

        work();
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