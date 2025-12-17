// O(n log n) - O(1)
// template <class T, T e, T (*F)(T, T)>, if cpp < 20
template <class T, T e, auto F>
struct SparseTable {
    int n;
    std::vector<std::vector<T>> a;
    SparseTable(const std::vector<T> &v = {}) {
        init(v);
    }
    void init(const std::vector<T> &v) {
        n = v.size();
        if (n == 0) {
            return;
        }
        const int m = std::__lg(n);
        a.assign(m + 1, std::vector<T>(n));
        a[0] = v;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i + (2 << j) <= n; i++) {
                a[j + 1][i] = F(a[j][i], a[j][i + (1 << j)]);
            }
        }
    }
    T operator()(int l, int r) const {
        if (l >= r) {
            return e;
        } else {
            const int k = std::__lg(r - l);
            return F(a[k][l], a[k][r - (1 << k)]);
        }
    }
};

// O(n) - O(1)
// only for minmax
template<class T, T e, class Cmp = std::less<>>
struct SparseTable {
    const Cmp cmp = Cmp();
    static constexpr unsigned B = 64;
    int n;
    std::vector<std::vector<T>> a;
    std::vector<T> pre, suf, ini;
    std::vector<u64> stk;
    SparseTable(const std::vector<T> &v = {}) {
        init(v);
    }
    void init(const std::vector<T> &v) {
        n = v.size();
        if (n == 0) {
            return;
        }
        pre = suf = ini = v;
        stk.resize(n);
        const int M = (n - 1) / B + 1;
        const int lg = std::__lg(M);
        a.assign(lg + 1, std::vector<T>(M));
        for (int i = 0; i < M; i++) {
            a[0][i] = v[i * B];
            for (int j = 1; j < B && i * B + j < n; j++) {
                a[0][i] = std::min(a[0][i], v[i * B + j], cmp);
            }
        }
        for (int i = 1; i < n; i++) {
            if (i % B) {
                pre[i] = std::min(pre[i], pre[i - 1], cmp);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (i % B != B - 1) {
                suf[i] = std::min(suf[i], suf[i + 1], cmp);
            }
        }
        for (int j = 0; j < lg; j++) {
            for (int i = 0; i + (2 << j) <= M; i++) {
                a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);
            }
        }
        for (int i = 0; i < M; i++) {
            const int l = i * B;
            const int r = std::min(1U * n, l + B);
            u64 s = 0;
            for (int j = l; j < r; j++) {
                while (s && cmp(v[j], v[std::__lg(s) + l])) {
                    s ^= 1ULL << std::__lg(s);
                }
                s |= 1ULL << (j - l);
                stk[j] = s;
            }
        }
    } 
    T operator()(int l, int r) {
        if (l >= r) {
            return e;
        }
        if (l / B != (r - 1) / B) {
            T ans = std::min(suf[l], pre[r - 1], cmp);
            l = l / B + 1;
            r = r / B;
            if (l < r) {
                int k = std::__lg(r - l);
                ans = std::min({ans, a[k][l], a[k][r - (1 << k)]}, cmp);
            }
            return ans;
        } else {
            int x = B * (l / B);
            return ini[__builtin_ctzll(stk[r - 1] >> (l - x)) + l];
        }
    }
};