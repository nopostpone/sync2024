#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

template <int D, const int *B, const int *P>
struct SeqHash {
    std::vector<std::array<int, D>> h;
    template <class Container>
    SeqHash(const Container &s) : h(s.size() + 1) {
        for (auto i = 0U; i < s.size(); i++) {
            for (int k = 0; k < D; k++) {
                i64 val = (1LL * s[i] % P[k] + P[k]) % P[k];
                h[i + 1][k] = (1LL * h[i][k] * B[k] + val + 1) % P[k];
            }
        }
    }
    SeqHash(const char *s) : SeqHash(std::string(s)) {}

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

    constexpr u64 filter_string(u64 x, const char* str, size_t index) {
        return str[index] == '\0' ? x : filter_string(chaos(x ^ static_cast<u64>(str[index])), str, index + 1);
    }

    constexpr u64 generate_seed() {
        return filter_string(filter_string(filter_string(1128471 ^ __LINE__, __TIME__, 0), __TIMESTAMP__, 0), __FILE__, 0);
    };

    constexpr u64 seed = generate_seed();

    template <unsigned int T>
    struct Rng { static constexpr u64 value = chaos(Rng<T - 1>::value); };

    template <>
    struct Rng<0> { static constexpr u64 value = seed; };
}

constexpr int HashDimension = 2;

constexpr int __B[HashDimension] = {
    static_cast<int>(compileRandom::Rng<13>::value % 133 + 133),
    static_cast<int>(compileRandom::Rng<31>::value % 331 + 331)
};

constexpr int __P[HashDimension] = {
    static_cast<int>(1E9) + 21,
    static_cast<int>(1E9) + 33
};

using Hash = SeqHash<HashDimension, __B, __P>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector a(m, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[j][i];
        }
    }

    if (n == 1 or k == 1) {
        std::cout << m * (m - 1) / 2 << "\n";
        return 0;
    }

    std::vector d(m, std::vector<int>(n - 1));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            d[j][i] = a[j][i + 1] - a[j][i];
        }
    }
    std::vector s(m, std::vector<std::array<int, 2>>(n - k + 1));
    for (int j = 0; j < m; j++) {
        Hash h(d[j]);
        for (int i = k - 1; i <= n - 1; i++) {
            s[j][i - (k - 1)] = h.get(i - (k - 1), i);
        }
        rgs::sort(s[j]);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            bool ok = false;
            for (int l = 0, r = 0; l < n - k + 1 and r < n - k + 1;) {
                if (s[i][l] == s[j][r]) {
                    ok = true;
                    break;
                } else if (s[i][l] > s[j][r]) {
                    r++;
                } else {
                    l++;
                }
            }
            ans += ok;
        }
    }
    std::cout << ans << "\n";
}