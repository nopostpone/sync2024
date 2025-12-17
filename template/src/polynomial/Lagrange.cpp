// n points -> n - 1 polynomial     O(n ^ 2)
for (int i = 0; i < n; i++) {
    Z num = y[i];
    Z den = 1;
    for (int j = 0; j < n; j++) {
        if (i == j) {
            continue;
        }
        num *= (k - x[j]); // f(k)
        den *= (x[i] - x[j]);
    }
    ans += num / den;
}

// Continuous x     O(n)
vector<Z> fac(n + 1);
fac[0] = 1;
for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
}

vector<Z> pre(n + 1);
pre[0] = 1;
for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] * (k - i);
}

vector<Z> suf(n + 1);
suf[n] = 1;
for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] * (k - i);
}

Z ans = 0;
for (int i = 0; i < n; i++) {
    Z res = y[i];
    res *= pre[i] * suf[i + 1];
    res /= ((n - 1 - i) % 2 ? -1 : 1) * fac[i] * fac[n - 1 - i];

    ans += res;
}