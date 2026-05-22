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
struct Barrett {
public:
    Barrett(u32 m_) : m(m_), im((u64)(-1) / m_ + 1) {}

    constexpr u32 mod() const {
        return m;
    }

    constexpr u32 mul(u32 a, u32 b) const {
        u64 z = a;
        z *= b;

        u64 x = u64((u128(z) * im) >> 64);

        u32 v = u32(z - x * m);
        if (m <= v) {
            v += m;
        }
        return v;
    }

private:
    u32 m;
    u64 im;
};

template <u32 Id>
struct DynModInt {
public:
    constexpr DynModInt() : x(0) {}
    template <std::unsigned_integral T>
    constexpr DynModInt(T x_) : x(x_ % mod()) {}
    template <std::signed_integral T>
    constexpr DynModInt(T x_) {
        int v = x_ % int(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }
    constexpr static void setMod(u32 m) {
        bt = m;
    }
    static u32 mod() {
        return bt.mod();
    }
    constexpr u32 val() const {
        return x;
    }
    constexpr DynModInt operator-() const {
        DynModInt res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }
    constexpr DynModInt inv() const {
        auto v = invGcd(x, mod());
        assert(v.first == 1);
        return v.second;
    }
    constexpr DynModInt &operator*=(const DynModInt &rhs) & {
        x = bt.mul(x, rhs.val());
        return *this;
    }
    constexpr DynModInt &operator+=(const DynModInt &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr DynModInt &operator-=(const DynModInt &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr DynModInt &operator/=(const DynModInt &rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr DynModInt operator*(DynModInt lhs, const DynModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator+(DynModInt lhs, const DynModInt &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr DynModInt operator-(DynModInt lhs, const DynModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator/(DynModInt lhs, const DynModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }
    friend constexpr std::istream &operator>>(std::istream &is, DynModInt &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const DynModInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(const DynModInt &lhs, const DynModInt &rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const DynModInt &lhs, const DynModInt &rhs) {
        return lhs.val() <=> rhs.val();
    }
private:
    u32 x;
    static Barrett bt;
};

template <u32 Id>
Barrett DynModInt<Id>::bt = 998244353;

using Z = DynModInt<998244353>;

using std::cerr;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, mod;
    std::cin >> n >> mod;

    Z::setMod(mod);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] xor a[i];
    }

    std::vector f(n + 1, std::vector<int>(n + 1, -1));
    std::vector g(n + 1, std::vector<Z>(n + 1));

    std::vector<std::vector<std::tuple<int, int, Z>>> pre(n + 1);

    for (int i = 1; i <= n; i++) {
        f[i][0] = 1;
        g[i][0] = 1;

        std::vector<std::pair<int, int>> states;
        for (int j = 1; j < i; j++) {
            int aij = s[i] xor s[j];

            int lo = 0, hi = pre[j].size();
            while (lo < hi) {
                int m = std::midpoint(lo, hi);
                if (std::get<0>(pre[j][m]) > aij) {
                    hi = m;
                } else {
                    lo = m + 1;
                }
            }
            if (lo > 0) {
                lo--;
                auto [_, nf, ng] = pre[j][lo];
                f[i][j] = nf + 1;
                g[i][j] = ng;
            }
        }
        for (int j = 0; j < i; j++) {
            if (f[i][j] != -1) {
                states.emplace_back(s[i] xor s[j], j);
            }
        }
        rgs::sort(states);
        Z cnt = 0;
        int res = 0;
        for (auto [v, j] : states) {
            if (f[i][j] > res) {
                res = f[i][j];
                cnt = g[i][j];
            } else if (res == f[i][j]) {
                cnt += g[i][j];
            }
            pre[i].emplace_back(v, res, cnt);
        }
    }

    Z cnt = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (f[n][i] > ans) {
            ans = f[n][i];
            cnt = g[n][i];
        } else if (f[n][i] == ans) {
            cnt += g[n][i];
        }
    }

    std::cout << ans << " " << cnt << "\n";
}