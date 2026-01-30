using i64 = long long;

constexpr int P = 998244353;

int norm(int x) {
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
    return x;
}
int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = 1ll * a * a % P) {
        if (b % 2) {
            res = 1ll * res * a % P;
        }
    }
    return res;
}

std::vector<int> rev, roots{0, 1};

void dft(std::vector<int> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    for (int i = 0; i < n; i++) {
        if (rev[i] < i) {
            std::swap(a[i], a[rev[i]]);
        }
    }
    if (roots.size() < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int e = power(31, 1 << (__builtin_ctz(P - 1) - k - 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1LL * roots[i] * e % P;
            }
            k++;
        }
    }

    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                int u = a[i + j];
                int v = 1LL * a[i + j + k] * roots[k + j] % P;
                a[i + j] = (u + v) % P;
                a[i + j + k] = (u - v) % P;
            }
        }
    }
}

void idft(std::vector<int> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    int inv = (1 - P) / n;
    for (int i = 0; i < n; i++) {
        a[i] = 1ll * a[i] * inv % P;
    }
}

using Poly = std::vector<int>;

Poly shift(Poly a, int k) {
    if (k >= 0) {
        a.insert(a.begin(), k, 0);
        return a;
    } else if (a.size() <= -k) {
        return Poly();
    } else {
        return Poly(a.begin() - k, a.end());
    }
}
Poly trunc(Poly a, int k) {
    k = std::min(k, (int)a.size());
    return Poly(a.begin(), a.begin() + k);
}

Poly operator+(const Poly &a, const Poly &b) {
    Poly res(std::max(a.size(), b.size()));
    for (int i = 0; i < a.size(); i++) {
        res[i] = a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        res[i] = norm(res[i] + b[i]);
    }
    return res;
}
Poly operator-(const Poly &a, const Poly &b) {
    Poly res(std::max(a.size(), b.size()));
    for (int i = 0; i < a.size(); i++) {
        res[i] = a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        res[i] = norm(res[i] - b[i]);
    }
    return res;
}
Poly operator-(const Poly &a) {
    Poly res(a.size());
    for (auto &x : res) {
        x = -x;
    }
    return res;
}
Poly operator*(Poly a, Poly b) {
    if (a.empty() or b.empty()) {
        return Poly();
    }
    if (a.size() < b.size()) {
        std::swap(a, b);
    }
    int n = 1;
    int tot = a.size() + b.size() - 1;
    while (n < tot) {
        n *= 2;
    }
    if (b.size() < 128) {
        Poly c(tot);
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] = norm(c[i + j] + 1ll * a[i] * b[j] % P);
            }
        }
        return c;
    }

    a.resize(n);
    b.resize(n);
    dft(a);
    dft(b);
    for (int i = 0; i < n; i++) {
        a[i] = 1ll * a[i] * b[i] % P;
    }
    idft(a);
    a.resize(tot);
    return std::move(a);
}

Poly operator*(Poly a, int b) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = 1ll * a[i] * b % P;
    }
    return a;
}
Poly operator/(Poly a, int b) {
    const int invb = power(b, P - 2);
    for (int i = 0; i < a.size(); i++) {
        a[i] = 1ll * a[i] * invb % P;
    }
    return a;
}

Poly deriv(const Poly &a) {
    if (a.empty()) {
        return Poly();
    }
    Poly res(a.size() - 1);
    for (int i = 0; i < res.size(); i++) {
        res[i] = 1ll * (i + 1) * a[i + 1] % P;
    }
    return res;
}
Poly integr(const Poly &a) {
    Poly res(a.size() + 1);
    for (int i = 0; i < a.size(); ++i) {
        res[i + 1] = 1ll * a[i] * power(i + 1, P - 2) % P;
    }
    return res;
}
Poly inv(const Poly &a, int m) {
    Poly x {power(a[0], P - 2)};
    for (int k = 1; k < m;) {
        k *= 2;
        x = (x * (Poly {2} - trunc(a, k) * x));
        x.resize(k);
    }
    x.resize(m);
    return x;
}
Poly log(Poly a, int m) {
    a = deriv(a) * inv(a, m);
    a = integr(a);
    a.resize(m);
    return a;
}
Poly exp(Poly a, int m) {
    Poly x {1};
    for (int k = 1; k < m;) {
        k *= 2;
        x = (x * (Poly {1} - log(x, k) + trunc(a, k)));
        x.resize(k);
    }
    x.resize(m);
    return x;
}