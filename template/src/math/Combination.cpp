{
    vector<int> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
    }
    invfac[n] = power(fac[n], P - 2);
    for (int i = n; i >= 1; i--) {
        invfac[i - 1] = mul(invfac[i], i);
    }
    auto binom = [&](int n, int m) -> int {
        if (n < m or m < 0) {
            return 0;
        }
        return i64(fac[n]) * invfac[m] % P * invfac[n - m] % P;
    };
}