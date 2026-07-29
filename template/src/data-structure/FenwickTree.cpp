template <class T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n = 0) {
        this->init(n);
    }
    void init(int n) : n(n) {
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

// 2-dimensional Fenwick
template <class T>
struct Fenwick {
    int n, m;
    std::vector<std::vector<T>> a;
    Fenwick(int n = 0, int m = 0) {
        init(n, m);
    }
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        a.assign(n, std::vector<T>(m, T{}));
    }
    void add(int x, int y, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= m; j += j & -j) {
                a[i - 1][j - 1] = a[i - 1][j - 1] + v;
            }
        }
    }
    T sum(int x, int y) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                ans = ans + a[i - 1][j - 1];
            }
        }
        return ans;
    }
    T rangeSum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
    }
};