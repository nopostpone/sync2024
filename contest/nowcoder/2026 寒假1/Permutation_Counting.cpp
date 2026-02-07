#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace IO {
    FILE *Fin(stdin), *Fout(stdout);
    class qistream {
        static const size_t SIZE = 1 << 20, BLOCK = 32;
        FILE *fp;
        char buf[SIZE];
        int p;

    public:
        qistream(FILE *_fp = stdin) : fp(_fp), p(0) { fread(buf + p, 1, SIZE - p, fp); }
        void flush() { memmove(buf, buf + p, SIZE - p), fread(buf + SIZE - p, 1, p, fp), p = 0; }
        qistream &operator>>(char &str) {
            str = getch();
            while (isspace(str))
                str = getch();
            return *this;
        }
        template <class T>
        qistream &operator>>(T &x) {
            x = 0;
            p + BLOCK >= SIZE ? flush() : void();
            bool flag = false;
            for (; !isdigit(buf[p]); ++p)
                flag = buf[p] == '-';
            for (; isdigit(buf[p]); ++p)
                x = x * 10 + buf[p] - '0';
            x = flag ? -x : x;
            return *this;
        }
        char getch() { return buf[p++]; }
        qistream &operator>>(char *str) {
            char ch = getch();
            while (ch <= ' ')
                ch = getch();
            for (int i = 0; ch > ' '; ++i, ch = getch())
                str[i] = ch;
            return *this;
        }
    } qcin(Fin);
    class qostream {
        static const size_t SIZE = 1 << 20, BLOCK = 32;
        FILE *fp;
        char buf[SIZE];
        int p;

    public:
        qostream(FILE *_fp = stdout) : fp(_fp), p(0) {}
        ~qostream() { fwrite(buf, 1, p, fp); }
        void flush() { fwrite(buf, 1, p, fp), p = 0; }
        template <class T>
        qostream &operator<<(T x) {
            int len = 0;
            p + BLOCK >= SIZE ? flush() : void();
            x < 0 ? (x = -x, buf[p++] = '-') : 0;
            do
                buf[p + len] = x % 10 + '0', x /= 10, ++len;
            while (x);
            for (int i = 0, j = len - 1; i < j; ++i, --j)
                swap(buf[p + i], buf[p + j]);
            p += len;
            return *this;
        }
        qostream &operator<<(char x) {
            putch(x);
            return *this;
        }
        void putch(char ch) {
            p + BLOCK >= SIZE ? flush() : void();
            buf[p++] = ch;
        }
        qostream &operator<<(const char *str) {
            for (int i = 0; str[i]; ++i)
                putch(str[i]);
            return *this;
        }
    } qcout(Fout);
}
using namespace IO;

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
    Z perm(int n, int m) {
        if (n < m || m < 0)
            return 0;
        return fac(n) * invfac(n - m);
    }
} comb;

void chmax(auto &a, auto b) {
    if (b > a) {
        a = b;
    }
}
void chmin(auto &a, auto b) {
    if (b < a) {
        a = b;
    }
}

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    qcin >> n >> m;

    vector<int> l1(n, -1), l2(n, n), r1(n, n), r2(n, -1);
    for (int i = 0; i < m; i++) {
        int l, r, k;
        qcin >> l >> r >> k;
        l--;
        k--;

        chmax(l1[k], l);
        chmin(r1[k], r);
        chmin(l2[k], l);
        chmax(r2[k], r);

    }

    DSU dsu(n + 1);
    
    Z ans = 1;
    int lst = -1;
    int cnt = 0;

    auto get = [&](int l, int r) {
        int res = 0;

        while (not dsu.same(l, r)) {
            res++;
            l = dsu.find(l);
            dsu.merge(l + 1, l);
            l = dsu.find(l);
        }
        return res;
    };
    
    for (int k = 0; k < n; k++) {
        if (l1[k] == -1) {
            continue;
        }
        cnt += k - lst - 1;

        int s1 = get(l1[k], r1[k]);
        int s2 = get(l2[k], r2[k]) + s1;

        ans *= s1;
        ans *= comb.perm(cnt, s2 - 1);
        cnt -= s2 - 1;
        lst = k;
    }
    
    cnt += n - lst - 1;
    ans *= comb.perm(cnt, get(0, n));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    qcin >> t;

    while (t--) {
        solve();
    }
}