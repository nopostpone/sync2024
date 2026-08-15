#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

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

using Z = ModInt<998244353>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> m;

    std::vector<int> s(m);
    for (int i = 0; i < m; i++) {
        std::cin >> s[i];
    }
    rgs::sort(s);

    Z ans = 0;
    Z prod = 1;

    for (int i = 0; i < m; i++) {
        Z term = 0;
        int rest = m - i;

        Z d = (Z(s[i]).pow(rest - 1) - Z(i ? s[i - 1] : 0).pow(rest - 1));
        if (rest % 2 == 0) {
            term = Z(rest) / (2 * (rest - 1)) * d;
        } else {
            term = d / 2;
        }

        ans += prod * term;
        prod *= s[i];
    }

    std::cout << ans << "\n";
}