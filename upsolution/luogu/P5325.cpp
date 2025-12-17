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

using Z = ModInt<1'000'000'007>;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

template <class T>
struct Min25 {
    using Func = T (*)(int, int, i64);
    int pcnt;
    i64 n, sqrt;
    std::vector<i64> nums;
    std::vector<T> coef;
    std::vector<std::vector<T>> sum, ini, val;
    Min25() : n{0}, sqrt{0} {}
    Min25(i64 n, const std::vector<T> &coef, const std::vector<Func> &func, u32 lim = -1) {
        init(n, coef, func, lim);
    }
    void init(i64 m, const std::vector<T> &coef, const std::vector<Func> &func, u32 lim = -1) {
        n = m;
        sqrt = std::sqrt(n);
        // pcnt = sieve.count(sqrt);
        pcnt = upper_bound(primes.begin(), primes.end(), sqrt) - primes.begin();
        nums.clear();
        for (i64 i = 1; i <= n; i = n / (n / i) + 1) {
            nums.emplace_back(n / i);
        }
        nums.emplace_back(0);
        std::reverse(nums.begin(), nums.end());
        sum.assign(func.size(), std::vector<T>(pcnt + 1));
        ini.assign(func.size(), std::vector<T>(nums.size()));
        for (int i = 0; i < func.size(); i++) {
            auto f = func[i];
            for (int j = 0; j < pcnt; j++) {
                // auto b = sieve.prime(j);
                auto b = primes[j];
                sum[i][j + 1] = sum[i][j] + f(b, 1, b);
            }
            auto c = f(0, 0, 1);
            for (int j = 1; j < nums.size(); j++) {
                ini[i][j] = f(0, 0, nums[j]) - c;
            }
        }
        for (int i = 0; i < func.size(); i++) {
            auto f = func[i];
            for (int j = 0; j < pcnt; j++) {
                // auto b = sieve.prime(j);
                auto b = primes[j];
                for (int k = nums.size() - 1; k > 0; k--) {
                    if (1LL * b * b > nums[k]) {
                        break;
                    }
                    ini[i][k] -= f(b, 1, b) * (ini[i][rank(nums[k] / b)] - sum[i][j]);
                }
            }
        }
        val.assign(pcnt, {});
        for (int i = 0; i < pcnt; i++) {
            // auto b = sieve.prime(i);
            auto b = primes[i];
            val[i].reserve(std::floor(std::log(n) / std::log(b)) + 1);
            val[i].emplace_back(0);
            for (i64 e = 1, p = b, c = 0; e <= lim && p <= n; e++, p *= b, c = 1) {
                val[i].emplace_back(0);
                for (int j = 0; j < coef.size(); j++) {
                    val[i][e] += coef[j] * func[j](b, e, p);
                }
            }
        }
        this->coef = coef;
    }
    int rank(i64 m) {
        if (m <= sqrt) {
            return m;
        } else {
            return nums.size() - n / m;
        }
    }
    T operator[](i64 m) {
        T res = 0;
        for (int i = 0; i < coef.size(); i++) {
            res += coef[i] * ini[i][rank(m)];
        }
        return res;
    }
    T dfs(i64 m, int i) {
        // if (sieve.prime(i) > m) {
        //     return 0;
        // }
        if (primes[i] > m) {
            return 0;
        }
        T res = 0;
        for (int j = 0; j < coef.size(); j++) {
            res += coef[j] * (ini[j][rank(m)] - sum[j][i]);
        }
        for (; i < pcnt; i++) {
            // auto b = sieve.prime(i);
            auto b = primes[i];
            if (1LL * b * b > m) {
                break;
            }
            for (i64 e = 1, p = b, c = 0; e < val[i].size() && p <= m; e++, p *= b, c = 1) {
                res += val[i][e] * (dfs(m / p, i + 1) + c);
            }
        }
        return res;
    }
    T operator()(i64 m) {
        return dfs(m, 0);
    }
};

constexpr Z inv6 = Z(6).inv();
constexpr Z inv2 = Z(2).inv();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(2e7);

    i64 n;
    cin >> n;

    auto f = [](int b, int e, i64 p) -> Z {
        if (b) {
            return Z(p) * p;
        }
        return Z(p) * (p + 1) * (2 * p + 1) * inv6;
    };
    auto g = [](int b, int e, i64 p) -> Z {
        if (b) {
            return p;
        }
        return Z(p) * (p + 1) * inv2;
    };

    Min25<Z> min25(n, {1, -1}, {f, g});

    cout << min25(n) + 1 << endl;

    return 0;
}