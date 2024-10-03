#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
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

constexpr ll inf = 1e13;

struct Node {
    ll val = -inf;
    int l = 0;
    int r = 0;
};

constexpr Node operator+(const Node &a, const Node &b) {
    // cerr << a.l << " " << a.r << " " << b.l << " " << b.r << endl;
    assert(a.r == b.l or a.l == b.r);
    return Node{a.val + b.val, min(a.l, b.l), max(a.r, b.r)};
}

bool check(const Node &x) {
    return x.r == 0;
}

bool cmp2(const Node &a, const Node &b) {
    return a.val == b.val ? (a.r - a.l) < (b.r - b.l) : a.val < b.val;
}

bool cmp1(const Node &a, const Node &b) {
    return a.val == b.val ? (a.r - a.l) > (b.r - b.l) : a.val < b.val;
}

struct minInfo {
    Node sum = Node();
    Node pre = Node();
    Node suf = Node();
    Node ans = Node();
};

minInfo operator+(const minInfo &a, const minInfo &b) {
    if (check(a.ans)) {
        return b;
    } else if (check(b.ans)) {
        return a;
    }
    minInfo c;

    c.pre = max(a.pre, a.sum + b.pre, cmp1);
    c.suf = max(b.suf, b.sum + a.suf, cmp1);
    c.sum = a.sum + b.sum;
    c.ans = max({a.ans, b.ans, a.suf + b.pre}, cmp1);
    
    return c;
}

struct maxInfo {
    Node sum = Node();
    Node pre = Node();
    Node suf = Node();
    Node ans = Node();
};

maxInfo operator+(const maxInfo &a, const maxInfo &b) {
    if (check(a.ans)) {
        return b;
    } else if (check(b.ans)) {
        return a;
    }
    maxInfo c;

    c.pre = max(a.pre, a.sum + b.pre, cmp2);
    c.suf = max(b.suf, b.sum + a.suf, cmp2);
    c.sum = a.sum + b.sum;
    c.ans = max({a.ans, b.ans, a.suf + b.pre}, cmp2);
    
    return c;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<maxInfo> c(n);
    for (int i = 0; i < n; i++) {
        c[i].ans = c[i].pre = c[i].suf = c[i].sum = Node{a[i], i, i + 1};
    }

    cerr << 1 << endl;
    SegmentTree<maxInfo> Max(c);
    cerr << 1 << endl;
    for (int i = 0; i < n; i++) {
        auto t = Max.rangeQuery(0, n).ans;
        cout << t.val << " \n"[i == n - 1];

        for (int j = t.l; j < t.r; j++) {
            Max.modify(j, maxInfo());
        }
    }

    vector<minInfo> b(n);
    for (int i = 0; i < n; i++) {
        b[i].ans = b[i].pre = b[i].suf = b[i].sum = Node{a[i], i, i + 1};
    }

    SegmentTree<minInfo> Min(b);
    for (int i = 0; i < n; i++) {
        auto t = Min.rangeQuery(0, n).ans;
        cout << t.val << " \n"[i == n - 1];

        for (int j = t.l; j < t.r; j++) {
            Max.modify(j, maxInfo());
        }
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