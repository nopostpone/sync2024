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

constexpr ll inf = -1e13;
using pii = pair<int, int>;

struct Info {
    ll val = -inf;
    int l = 0;
    int r = 0;
};

struct minInfo {
    ll sum = -inf;
};

minInfo operator+(const minInfo &a, const minInfo &b) {
    if (b.preidx == pii{}) {
        return a;
    } else if (a.preidx == pii{}) {
        return b;
    }
    minInfo c;
    

    return c;
}

struct maxInfo {
};

maxInfo operator+(const maxInfo &a, const maxInfo &b) {
    if (b.preidx == pii{}) {
        return a;
    } else if (a.preidx == pii{}) {
        return b;
    }
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
    }

    SegmentTree<maxInfo> Max(c);
    for (int i = 0; i < n; i++) {
    }

    vector<minInfo> b(n);
    for (int i = 0; i < n; i++) {
    }

    SegmentTree<minInfo> Min(b);
    for (int i = 0; i < n; i++) {
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