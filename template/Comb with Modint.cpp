template <class T>
struct Comb {
    int n;
    std::vector<T> _fac;
    std::vector<T> _invfac;

    constexpr Comb() : n{0}, _fac{1}, _invfac{1} {}
    Comb(int n) : Comb() { init(n); }

    void init(int m) {
        if (m <= n) {
            return;
        }
        _fac.resize(m + 1);
        _invfac.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
        }
        n = m;
    }
    T fac(int m) {
        if (m > n) {
            init(2 * m);
        }
        return _fac[m];
    }
    T invfac(int m) {
        if (m > n) {
            init(2 * m);
        }
        return _invfac[m];
    }
    T inv(int m) {
        if (m > n) {
            init(2 * m);
        }
        return _inv[m];
    }
    T P(int n, int m) {
        if (n < m or m < 0) {
            return {};
        }
        return fac(n) * invfac(n - m);
    }
    T C(int n, int m) {
        if (n < m or m < 0) {
            return {};
        }
        return fac(n) * invfac(m) * invfac(n - m);
    }
};
Comb<Z> comb;