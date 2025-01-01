template <int D, array<int, D> B, array<int, D> P>
struct StringHash {
    vector<array<int, D>> h;

    template <class T>
    StringHash(const T &s) : h(s.size() + 1) {
        for (int i = 0; i < s.size(); i++) {
            for (int k = 0; k < D; k++) {
                h[i + 1][k] = (1ll * h[i][k] * B[k] + s[i] + 1) % P[k];
            }
        }
    }

    // [l, r)
    array<int, D> get(int l, int r) {
        static vector<array<int, D>> spow(1);
        assert(l < r);

        if (spow.size() < r - l + 1) {
            if (spow[0][0] == 0) {
                spow[0].fill(1);
            }
            int n = spow.size();
            spow.resize(r - l + 1);
            for (int i = n; i < spow.size(); i++) {
                for (int k = 0; k < D; k++) {
                    spow[i][k] = 1ll * spow[i - 1][k] * B[k] % P[k];
                }
            }
        }

        array<int, D> res = {};
        for (int k = 0; k < D; k++) {
            res[k] = h[r][k] - 1LL * h[l][k] * spow[r - l][k] % P[k];
            res[k] += (res[k] < 0 ? P[k] : 0);
        }
        return res;
    }
};

using u64 = unsigned long long;

namespace compileRandom {
    constexpr u64 chaos(u64 x) {
        x ^= x << 3;
        x ^= x >> 13;
        x ^= x >> 7;
        return x;
    }

    constexpr u64 seed = [] {
        u64 x = 1128471 ^ __LINE__;
        for (char c : __TIME__ __TIMESTAMP__ __FILE__) {
            x = chaos(x ^ c);
        }
        return x;
    }();

    template <unsigned int T>
    constexpr u64 rng = chaos(rng<T - 1>);

    template <>
    constexpr u64 rng<0> = seed;
}

constexpr int HashDimension = 2;
using Hash = StringHash<
    HashDimension,
    array<int, HashDimension>{
        int(compileRandom::rng<13> % 133 + 133),
        int(compileRandom::rng<31> % 331 + 331)},
    array<int, HashDimension>{
        int(1E9) + 21,
        int(1E9) + 33}>;