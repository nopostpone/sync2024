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

using Z = ModInt<998244353>;

struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        if (m <= n) {
            return;
        }
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    Z fac(int m) {
        if (m > n)
            init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n)
            init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n)
            init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {
        if (n < m || m < 0)
            return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> siz(n), son(n);

    vector ans(n, vector<Z>(n));
    ans[0][0] = 1;

    [&](this auto &&self, int x, int p) -> void {
        siz[x] = 1;

        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            son[x]++;
            self(y, x);
            siz[x] += siz[y];
        }
        ans[0][0] *= comb.fac(son[x]);

    } (0, -1);

    vector dp(n, vector<Z>(n));
    
    basic_string vis(n, false);
    queue<int> q;

    vis[0] = true;
    q.push(0);

    while (not q.empty()) {
        int x = q.front();
        q.pop();

        int m = son[x];
        vector g(m + 1, vector<Z>(n));
        g[0][0] = 1;

        for (auto y : adj[x]) {
            if (vis[y]) {
                continue;
            }
            for (int i = m; i >= 1; i--) {
                for (int j = siz[x] - 1; j >= siz[y]; j--) {
                    g[i][j] += g[i - 1][j - siz[y]];
                }
            }
        }

        for (auto y : adj[x]) {
            if (vis[y]) {
                continue;
            }
            for (int i = 1; i <= m; i++) {
                for (int j = siz[y]; j < siz[x]; j++) {
                    g[i][j] -= g[i - 1][j - siz[y]];
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < siz[x]; j++) {
                    dp[y][j] += g[i][j] * comb.fac(i) * comb.fac(m - i - 1);
                }
            }
            for (int i = m; i >= 1; i--) {
                for (int j = siz[x] - 1; j >= siz[y]; j--) {
                    g[i][j] += g[i - 1][j - siz[y]];
                }
            }

            Z t = accumulate(dp[y].begin(), dp[y].end(), Z()).inv();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    ans[y][j] += ans[x][j - i - 1] * dp[y][i] * t;
                }
            }
            
            vis[y] = true;
            q.push(y);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1]; 
        }
    }

    return 0;
}

/*
6
1 2
1 3
3 4
3 5
3 6

12 0 0 0 0 0
0 6 0 0 0 6
0 6 6 0 0 0
0 0 2 4 4 2
0 0 2 4 4 2
0 0 2 4 4 2

*/