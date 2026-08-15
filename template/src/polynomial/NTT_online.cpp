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
constexpr u64 mulMod(u64 a, u64 b) { return static_cast<u64>((static_cast<unsigned __int128>(a) * b) % P); }
template <std::unsigned_integral U, U P>
struct ModIntBase {
    using M = ModIntBase;

public:
    constexpr ModIntBase() : x(0) {}
    template <std::unsigned_integral T>
    constexpr ModIntBase(T x_) : x(x_ % mod()) {}
    template <std::signed_integral T>
    constexpr ModIntBase(T x_) {
        using L = std::conditional_t<sizeof(U) <= 4, i64, i128>;
        L v = static_cast<L>(x_) % static_cast<L>(mod());
        if (v < 0) {
            v += mod();
        }
        x = static_cast<U>(v);
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

using Z = ModInt<998244353>;

constexpr u32 get_primitive_root(u32 P) {
    if (P == 2)
        return 1;
    u32 m = P - 1;
    u32 divs[20] = {};
    int cnt = 0;
    u32 x = m;

    for (u32 i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }

    for (u32 g = 2; g < P; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            u64 a = g;
            u32 b = m / divs[i];
            u64 res = 1;
            for (; b != 0; b /= 2, a = (a * a) % P) {
                if (b & 1)
                    res = (res * a) % P;
            }
            if (res == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return g;
        }
    }
    return 0;
}

std::vector<int> rev;
std::vector<Z> roots{0, 1};

void dft(std::vector<Z> &a) {
    int n = a.size();

    if (static_cast<int>(rev.size()) != n) {
        int k = std::countr_zero(static_cast<unsigned>(n)) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
        }
    }
    for (int i = 0; i < n; i++) {
        if (rev[i] < i) {
            std::swap(a[i], a[rev[i]]);
        }
    }
    if (static_cast<int>(roots.size()) < n) {
        int k = std::countr_zero(static_cast<unsigned>(roots.size()));
        roots.resize(n);

        constexpr u32 G = get_primitive_root(Z::mod());

        while ((1 << k) < n) {
            Z e = Z(G).pow((Z::mod() - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                Z u = a[i + j];
                Z v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}

void idft(std::vector<Z> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);

    Z inv = Z(n).inv();
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}

std::vector<Z> convolution(std::vector<Z> a, std::vector<Z> b) {
    if (a.empty() || b.empty()) {
        return {};
    }

    int sz = a.size() + b.size() - 1;
    int n = std::bit_ceil(static_cast<unsigned>(sz));

    a.resize(n);
    b.resize(n);

    dft(a);
    dft(b);
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }

    idft(a);
    a.resize(sz);
    return a;
}