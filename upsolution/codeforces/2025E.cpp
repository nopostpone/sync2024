#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ull = unsigned long long;
using uint = unsigned int;
template <typename T>
constexpr T power(T a, ull b) {
    T res{1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template <uint P>
constexpr uint mulMod(uint a, uint b) {
    return 1ULL * a * b % P;
}

template <ull P>
constexpr ull mulMod(ull a, ull b) {
    ull res = a * b - ull(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template <typename U, U P>
    requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x(0) {}

    template <typename T>
        requires std::integral<T>
    constexpr ModIntBase(T x_) : x(norm(x_ % T{P})) {}

    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }

    constexpr U val() const {
        return x;
    }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }

    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }

    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }

    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
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

    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }

private:
    U x;
};

template <uint P>
using ModInt = ModIntBase<uint, P>;

template <ull P>
using ModInt64 = ModIntBase<ull, P>;

constexpr uint P = 998244353;
using Z = ModInt<P>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Z> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        vector<Z> ndp(m + 1);
        for (int j = i; j >= 0; j--) {
            ndp[j + 1] += dp[j];
            if (j) {
                ndp[j - 1] += dp[j];
            }
        }
        dp = move(ndp);
    }

    vector<Z> f(m + 1);
    f[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        vector<Z> nf(m + 1);
        for (int x = 0; x <= m; x++) {
            for (int y = 0; x + y <= m; y++) {
                nf[x + y] += f[x] * dp[y];
            }
        }
        f = move(nf);
    }

    Z ans{};
    for (int i = 0; i <= m; i++) {
        ans += dp[i] * f[i];
    }
    cout << ans << "\n";

    return 0;
}