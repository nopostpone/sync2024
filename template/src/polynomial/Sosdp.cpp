{
    std::vector<int> f(1 << n);
    // ...

    // prefix
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < 1 << n; s++) {
            if (s >> i & 1) {
                f[s] += f[s ^ (1 << i)];
            }
        }
    }
    // suffix
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < 1 << n; s++) {
            if (~s >> i & 1) {
                f[s] += f[s ^ (1 << i)];
            }
        }
    }
}