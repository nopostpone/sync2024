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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a);

    constexpr int N = 5000;

    vector dp(n + 1, vector<Z>(N + 1));
    dp[0][0] = 1;

    auto sum = dp;
    

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= 5000; k++) {
            if (k >= a[i - 1]) {
                dp[i][k] += sum[i - 1][k - a[i - 1]];
            }
            sum[i][k] = sum[i - 1][k] + dp[i][k];
        }
    }

    Z ans{};
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 5000; k++) {
            ans += dp[i][k] * max((k - 1) / 2 + 1, a[i - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}