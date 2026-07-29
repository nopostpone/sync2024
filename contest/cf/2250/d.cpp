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

std::mt19937_64 rng{std::chrono::steady_clock::now().time_since_epoch().count()};

Z solve() {
    int n;
    std::cin >> n;

    // n = 2e5;

    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> a[i];
        a[i]--;

        // a[i] = rng() % (n - 1);
    }

    if (rgs::max(a) != n - 2) {
        return 0;
    }
    int L = 0;
    while (L < n - 1 and a[L] != n - 2) {
        L++;
    }
    int R = n - 2;
    while (R >= 0 and a[R] != n - 2) {
        R--;
    }

    for (int i = L; i <= R; i++) {
        if (a[i] != n - 2) {
            return 0;
        }
    }
    for (int i = 0; i < L; i++) {
        if (a[i] > a[i + 1]) {
            return 0;   
        }
    }
    // std::cerr << 1 << "\n";
    for (int i = n - 2; i > R; i--) {
        if (a[i - 1] < a[i]) {
            return 0;
        }
    }

    // std::cerr << 1 << "\n";

    std::vector<bool> fix(n);
    fix[n - 1] = fix[n - 2] = true;
    auto safeFix = [&](int x) {
        assert(0 <= x and x < n);
        if (fix[x]) {
            return false;
        }
        fix[x] = true;
        return true;
    };

    std::vector<int> b;
    for (int i = 0; i < L; i++) {
        if (i == 0 or a[i] > a[i - 1]) {
            if (not safeFix(a[i])) {
                return 0;
            }
        } else {
            b.push_back(a[i]);
        }
    }
    for (int i = L; i < R; i++) {
        b.push_back(n - 2);
    }
    for (int i = n - 2; i > R; i--) {
        if (i == n - 2 or a[i] > a[i + 1]) {
            if (not safeFix(a[i])) {
                return 0;
            }
        } else {
            b.push_back(a[i]);
        }
    }

    rgs::sort(b);

    std::vector<int> cand;
    for (int i = 0; i < n; i++) {
        if (not fix[i]) {
            cand.push_back(i);
        }
    }

    Z ans = 2;
    for (int i = 0; i < b.size(); i++) {
        int cnt = rgs::upper_bound(cand, b[i]) - cand.begin();
        ans *= std::max(0, cnt - i);
    }

    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    // std::mt19937_64 rng{std::chrono::steady_clock::now().time_since_epoch().count()};

    // auto get = [&](int n) {

    // };

    while (t--) {
        std::cout << solve() << "\n";
    }
}
