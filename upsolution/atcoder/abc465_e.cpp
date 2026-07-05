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

bool vis[501][3][2][1024];
Z f[501][3][2][1024];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string N;
    std::cin >> N;

    Z ans = [&](this auto &&self, int p, int sum, int has3, int mask, bool lim, bool lead) -> Z {
        if (p == N.size()) {
            if (lead) {
                return Z();
            }
            return Z((sum == 0) + has3 + (__builtin_popcount(mask) == 3) == 1);
        }

        if (not lim and not lead and vis[p][sum][has3][mask]) {
            return f[p][sum][has3][mask];
        }

        Z res = 0;
        int bound = lim ? (N[p] - '0') : 9;

        for (int d = 0; d <= bound; d++) {
            if (lead and d == 0) {
                res += self(p + 1, 0, 0, 0, lim and (d == bound), true);
            } else {
                int nsum = (sum + d) % 3;
                int nhas = has3 | (d == 3);
                int nmask = mask | (1 << d);

                res += self(p + 1, nsum, nhas, nmask, lim and (d == bound), false);
            }
        }
        if (not lim and not lead) {
            vis[p][sum][has3][mask] = true;
            f[p][sum][has3][mask] = res;
        }

        return res;

    } (0, 0, 0, 0, true, true);

    std::cout << ans << "\n";
}
