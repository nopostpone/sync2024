#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

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
constexpr u32 mulMod(u32 a, u32 b) {
    return u64(a) * b % P;
}
template <u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}
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
template <std::unsigned_integral U, U P>
struct ModIntBase {
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
    constexpr static U mod() {
        return P;
    }
    constexpr U val() const {
        return x;
    }
    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }
    constexpr ModIntBase inv() const {
        return power(*this, mod() - 2);
    }
    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<mod()>(x, rhs.val());
        return *this;
    }
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::istream &operator>>(std::istream &is, ModIntBase &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(const ModIntBase &lhs, const ModIntBase &rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const ModIntBase &lhs, const ModIntBase &rhs) {
        return lhs.val() <=> rhs.val();
    }

private:
    U x;
};

template <u32 P>
using ModInt = ModIntBase<u32, P>;
template <u64 P>
using ModInt64 = ModIntBase<u64, P>;

constexpr int $ = 1e9 + 7;
using Z = ModInt<$>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    Z dp[2][2]{};
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        Z ndp[2][2] {};

        if (s[i] != '?' and t[i] != '?') {
            if (s[i] > t[i]) {
                for (int j = 0; j < 2; j++) {
                    ndp[1][j] = dp[0][j] + dp[1][j];
                }
            }
            if (s[i] < t[i]) {
                for (int j = 0; j < 2; j++) {
                    ndp[j][1] = dp[j][0] + dp[j][1];
                }
            }
            if (s[i] == t[i]) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        ndp[j][k] = dp[j][k];
                    }
                }
            }
        } else if (s[i] == '?' and t[i] == '?') {
            ndp[0][0] = dp[0][0] * 10;

            ndp[1][0] += dp[0][0] * 45;
            ndp[1][0] += dp[1][0] * 55;

            ndp[0][1] += dp[0][0] * 45;
            ndp[0][1] += dp[0][1] * 55;

            ndp[1][1] += dp[1][0] * 45;
            ndp[1][1] += dp[0][1] * 45;
            ndp[1][1] += dp[1][1] * 100;
        } else if (s[i] == '?') {
            int x = t[i] - '0';
            ndp[0][0] = dp[0][0];

            ndp[1][0] += dp[0][0] * (9 - x);
            ndp[1][0] += dp[1][0] * (10 - x);

            ndp[0][1] += dp[0][0] * x;
            ndp[0][1] += dp[0][1] * (x + 1);

            ndp[1][1] = (9 - x) * dp[0][1] + x * dp[1][0] + 10 * dp[1][1];
        } else {
            int x = s[i] - '0';
            ndp[0][0] = dp[0][0];

            ndp[1][0] += dp[0][0] * x;
            ndp[1][0] += dp[1][0] * (x + 1);

            ndp[0][1] += dp[0][0] * (9 - x);
            ndp[0][1] += dp[0][1] * (10 - x);

            ndp[1][1] = x * dp[0][1] + (9 - x) * dp[1][0] + 10 * dp[1][1];
        }

        swap(dp, ndp);
    }

    cout << dp[1][1] << "\n";

    return 0;
}