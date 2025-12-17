void andFwt(auto &a, int t) {
    int n = a.size();
    for (int i = 1; i < n; i *= 2) {
        for (int s = 0; s < n; s++) {
            if (~s & i) {
                a[s] += t * a[s | i];
            }
        }
    }
}
void orFwt(auto &a, int t) {
    int n = a.size();
    for (int i = 1; i < n; i *= 2) {
        for (int s = 0; s < n; s++) {
            if (~s & i) {
                a[s | i] += t * a[s];
            }
        }
    }
}
void xorFwt(auto &a) {
    int n = a.size();
    for (int i = 1; i < n; i *= 2) {
        for (int j = 0; j < n; j += 2 * i) {
            for (int k = 0; k < i; k++) {
                auto u = a[j + k], v = a[i + j + k];
                a[j + k] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
auto xorConv(auto a, auto b) {
    int n = a.size();
    xorFwt(a);
    xorFwt(b);

    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }
    xorFwt(a);
    auto invn = Z(n).inv();
    for (int i = 0; i < n; i++) {
        a[i] *= invn;
    }
    // if not module:
    // for (int i = 0; i < n; i++) {
    //     a[i] >>= __lg(n);
    // }
    return move(a);
}