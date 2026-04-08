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

constexpr int P = 998244353;

using Z = ModInt<P>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Z> inv(2 * n + 1);
    inv[1] = 1;
    for (int i = 2; i <= 2 * n; i++) {
        inv[i] = (P - P / i) * inv[P % i];
    }

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> f(2 * n, m), g(m, m);
    for (int i = m - 1; i >= 0; i--) {
        g[i] = f[a[i]];
        f[a[i]] = i;
    }

    vector<int> d(m);
    for (int i = m - 2; i >= 0; i--) {
        if (g[i] != m) {
            d[i] = max(d[i + 1] + 1, d[g[i]] + n + 1);
        } else {
            d[i] = d[i + 1] + 1;
        }
    }
    vector<int> w;
    for (int i = 0; i < 2 * n; i++) {
        if (f[i] != m) {
            w.push_back(d[f[i]]);
        }
    }
    ranges::sort(w, greater());

    Z ans = w[0] + n + 1;
    for (int k = w[0] + 1; k <= w[0] + n; k++) {
        Z res = 1;
        for (int i = 0; i < w.size(); i++) {
            res *= inv[2 * n - i];
            res *= (min(2 * n, k - w[i] + n - 1) - i);
        }
        ans -= res;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}