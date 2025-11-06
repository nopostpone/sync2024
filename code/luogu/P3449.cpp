#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <int D, const int *B, const int *P>
struct StringHash {
    std::vector<std::array<int, D>> h;

    template <class T>
    StringHash(const T &s) : h(s.size() + 1) {
        for (auto i = 0U; i < s.size(); i++) {
            for (int k = 0; k < D; k++) {
                h[i + 1][k] = (1LL * h[i][k] * B[k] + s[i] + 1) % P[k];
            }
        }
    }

    StringHash(const char *s) : StringHash(std::string(s)) {}

    // [l, r)
    std::array<int, D> get(int l, int r) {
        static std::vector<std::array<int, D>> spow(1);
        assert(l < r);

        if (static_cast<int>(spow.size()) < r - l + 1) {
            if (spow[0][0] == 0) {
                spow[0].fill(1);
            }
            int n = spow.size();
            spow.resize(r - l + 1);
            for (int i = n; i < static_cast<int>(spow.size()); i++) {
                for (int k = 0; k < D; k++) {
                    spow[i][k] = 1LL * spow[i - 1][k] * B[k] % P[k];
                }
            }
        }

        std::array<int, D> res = {};
        for (int k = 0; k < D; k++) {
            res[k] = h[r][k] - 1LL * h[l][k] * spow[r - l][k] % P[k];
            res[k] += (res[k] < 0 ? P[k] : 0);
        }
        return res;
    }
};

namespace compileRandom {
    constexpr u64 chaos(u64 x) {
        return ((x ^ (x << 3)) ^ ((x ^ (x << 3)) >> 13)) ^
               (((x ^ (x << 3)) ^ ((x ^ (x << 3)) >> 13)) << 7);
    }

    constexpr u64 filter_string(u64 x, const char *str, size_t index) {
        return str[index] == '\0' ? x : filter_string(chaos(x ^ static_cast<u64>(str[index])), str, index + 1);
    }

    constexpr u64 generate_seed() {
        return filter_string(filter_string(filter_string(1128471 ^ __LINE__, __TIME__, 0), __TIMESTAMP__, 0), __FILE__, 0);
    };

    constexpr u64 seed = generate_seed();

    template <unsigned int T>
    struct Rng {
        static constexpr u64 value = chaos(Rng<T - 1>::value);
    };

    template <>
    struct Rng<0> {
        static constexpr u64 value = seed;
    };
}

constexpr int HashDimension = 2;

constexpr int __B[HashDimension] = {
    static_cast<int>(compileRandom::Rng<13>::value % 133 + 133),
    static_cast<int>(compileRandom::Rng<31>::value % 331 + 331)};

constexpr int __P[HashDimension] = {
    static_cast<int>(1E9) + 21,
    static_cast<int>(1E9) + 33};

using Hash = StringHash<HashDimension, __B, __P>;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    vector<int> len(n);
    for (int i = 0; i < n; i++) {
        cin >> len[i] >> s[i];
    }

    const int L = ranges::max(len);
    sieve(L);

    auto work = [](const string &s) {
        int len = s.size();

        Hash h(s);

        int ans = len;
        while (len > 1) {
            int p = ::minp[len];
            len /= p;

            if (h.get(0, s.size() - ans / p) == h.get(ans / p, s.size())) {
                ans /= p;
            }
        }
        return h.get(0, ans);
    };

    map<array<int, 2>, int> cnt;
    for (int i = 0; i < n; i++) {
        auto h = work(s[i]);
        cnt[h]++;
    }

    i64 ans = 0;
    for (auto [x, c] : cnt) {
        ans += 1ll * c * c;
    }

    cout << ans << "\n";

    return 0;
}