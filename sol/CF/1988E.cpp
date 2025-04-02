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

constexpr int inf = 1e9;

struct Info {
    int max = -inf;
    int min = inf;
};

Info operator+(const Info &a, const Info &b) {
    return {max(a.max, b.max), min(a.min, b.min)};
}

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(i, {a[i], a[i]});
    }

    vector<int> l(n), r(n), l2(n), r2(n);
    for (int i = 0; i < n; i++) {
        l[i] = seg.findLast(0, i, [&](const auto &v) {
            return v.min < a[i];
        });
        r[i] = seg.findFirst(i + 1, n, [&](const auto &v) {
            return v.min < a[i];
        });
        if (r[i] == -1) {
            r[i] = n;
        }
        l2[i] = seg.findLast(0, l[i], [&](const auto &v) {
            return v.min < a[i];
        });
        r2[i] = seg.findFirst(r[i] + 1, n, [&](const auto &v) {
            return v.min < a[i];
        });
        if (r2[i] == -1) {
            r2[i] = n;
        }
    }

    i64 ori = 0;
    for (int i = 0; i < n; i++) {
        ori += 1ll * (r[i] - i) * (i - l[i]) * a[i];
    }

    vector<i64> f(n + 1);
    f[0] = ori;
    auto rangeAdd = [&](int x, int y, i64 k) {
        f[x] += k;
        f[y] -= k;
    };

    for (int i = 0; i < n; i++) {
        if (l[i] != -1) {
            rangeAdd(l[i], l[i] + 1, 1ll * (r[i] - i) * (l[i] - l2[i] - 1) * a[i]);
        }
        rangeAdd(l[i] + 1, i, -1ll * (r[i] - i) * a[i]);
        rangeAdd(i, i + 1, -1ll * (r[i] - i) * (i - l[i]) * a[i]);
        rangeAdd(i + 1, r[i], -1ll * (i - l[i]) * a[i]);
        if (r[i] != n) {
            rangeAdd(r[i], r[i] + 1, 1ll * (i - l[i]) * (r2[i] - r[i] - 1) * a[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << f[i] << " \n"[i == n - 1];
        f[i + 1] += f[i];
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
