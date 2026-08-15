template <class T>
constexpr T power(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}
template <u32 P>
constexpr u32 mulMod(u32 a, u32 b) { return u64(a) * b % P; }
template <u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}
template <std::unsigned_integral U, U P>
struct ModIntBase {
    using M = ModIntBase;

public:
    constexpr ModIntBase() : x(0) {}
    template <std::unsigned_integral T>
    constexpr ModIntBase(T x_) : x(x_ % mod()) {}
    template <std::signed_integral T>
    constexpr ModIntBase(T x_) {
        using S = std::make_signed_t<U>;
        S v = x_ % S(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }
    constexpr static U mod() { return P; }
    constexpr U val() const { return x; }
    constexpr M operator-() const {
        M res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }
    constexpr M inv() const { return power(*this, mod() - 2); }
    constexpr M pow(u64 b) const { return power(*this, b); }
    constexpr M &operator*=(const M &rhs) & {
        x = mulMod<mod()>(x, rhs.val());
        return *this;
    }
    constexpr M &operator+=(const M &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr M &operator-=(const M &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr M &operator/=(const M &rhs) & { return *this *= rhs.inv(); }
    friend constexpr M operator*(M lhs, const M &rhs) { return lhs *= rhs; }
    friend constexpr M operator+(M lhs, const M &rhs) { return lhs += rhs; }
    friend constexpr M operator-(M lhs, const M &rhs) { return lhs -= rhs; }
    friend constexpr M operator/(M lhs, const M &rhs) { return lhs /= rhs; }

    friend constexpr std::istream &operator>>(std::istream &is, M &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const M &a) { return os << a.val(); }

    friend constexpr bool operator==(const M &lhs, const M &rhs) { return lhs.val() == rhs.val(); }
    friend constexpr std::strong_ordering operator<=>(const M &lhs, const M &rhs) { return lhs.val() <=> rhs.val(); }

private:
    U x;
};
template <u32 P>
using ModInt = ModIntBase<u32, P>;
template <u64 P>
using ModInt64 = ModIntBase<u64, P>;

constexpr i64 safeMod(i64 x, i64 m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}
constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
    a = safeMod(a, b);
    if (a == 0) {
        return {b, 0};
    }
    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;
    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        std::swap(s, t);
        std::swap(m0, m1);
    }
    if (m0 < 0) {
        m0 += b / s;
    }
    return {s, m0};
}

std::vector<int> rev;
template <u32 P>
std::vector<ModInt<P>> roots{0, 1};

template <u32 P>
constexpr ModInt<P> findPrimitiveRoot() {
    ModInt<P> i = 2;
    int k = __builtin_ctz((int)P - 1);
    while (true) {
        if (power(i, (P - 1) / 2) != 1) {
            break;
        }
        i += 1;
    }
    return power(i, (P - 1) >> k);
}

template <u32 P>
constexpr ModInt<P> primitiveRoot = findPrimitiveRoot<P>();

template <>
constexpr ModInt<998244353> primitiveRoot<998244353>{31};

template <u32 P>
using Poly = std::vector<ModInt<P>>;

template <u32 P>
void dft(Poly<P> &a) {
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

    if (roots<P>.size() < n) {
        int k = __builtin_ctz(roots<P>.size());
        roots<P>.resize(n);
        while ((1 << k) < n) {
            auto e = power(primitiveRoot<P>, 1 << (__builtin_ctz(P - 1) - k - 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots<P>[2 * i] = roots<P>[i];
                roots<P>[2 * i + 1] = roots<P>[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                ModInt<P> u = a[i + j];
                ModInt<P> v = a[i + j + k] * roots<P>[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}

template <u32 P>
void idft(Poly<P> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    ModInt<P> inv = (1 - (int)P) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}

template <u32 P>
auto convolution(const std::vector<int> &u, const std::vector<int> &v) {
    if (u.empty() or v.empty()) {
        return Poly<P>();
    }
    int n = 1, tot = u.size() + v.size() - 1;
    while (n < tot) {
        n *= 2;
    }
    if (((P - 1) & (n - 1)) != 0 or std::max(u.size(), v.size()) < 128) {
        Poly<P> c(tot);
        for (int i = 0; i < u.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                c[i + j] += ModInt<P>(u[i]) * ModInt<P>(v[j]);
            }
        }
        return std::move(c);
    }

    Poly<P> a(n);
    for (int i = 0; i < u.size(); i++) {
        a[i] = u[i];
    }
    Poly<P> b(n);
    for (int i = 0; i < v.size(); i++) {
        b[i] = v[i];
    }
    dft<P>(a);
    dft<P>(b);
    for (int i = 0; i < n; ++i) {
        a[i] *= b[i];
    }
    idft<P>(a);
    a.resize(tot);
    return a;
}

auto convolution(const std::vector<int> &a, const std::vector<int> &b, int P) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m)
        return {};

    static constexpr u32 MOD1 = 1004535809; // 479 * 2^21 + 1
    static constexpr u32 MOD2 = 1107296257; // 33 * 2^25 + 1
    static constexpr u32 MOD3 = 2013265921; // 15 * 2^27 + 1

    static constexpr i64 inv1_2 = invGcd(MOD1, MOD2).second;
    static constexpr i64 inv12_3 = invGcd((i64)MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<int> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        i64 v1 = c1[i].val(), v2 = c2[i].val(), v3 = c3[i].val();

        i64 K = (v2 - v1) % MOD2;
        if (K < 0)
            K += MOD2;
        K = (K * inv1_2) % MOD2;

        i64 X = v1 + K * MOD1;

        i64 Y = (v3 - X % MOD3) % MOD3;
        if (Y < 0)
            Y += MOD3;
        Y = (Y * inv12_3) % MOD3;

        i128 ans = X;
        ans += (i128)Y * MOD1 * MOD2;

        c[i] = (ans % P);
    }
    return c;
}