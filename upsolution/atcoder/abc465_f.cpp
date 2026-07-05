#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr int p[7] {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> s(n);
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> v[i];
    }

    static std::array<i64, p[6]> dp {};

    for (int i = 0; i < n; i++) {
        dp[s[i]] += v[i];
    }

    for (int k = 0; k < 6; k++) {
        for (int i = 0; i < p[6]; i++) {
            int dig = (i / p[k]) % 10;
            if (dig != 0) {
                dp[i] += dp[i - p[k]];
            }
        }
    }


    int q;
    std::cin >> q;

    for (int _ = 0; _ < q; _++) {
        int x, y;
        std::cin >> x >> y;

        i64 ans = 0;
        
        for (int t = 0; t < 64; t++) {
            int sign = (__builtin_popcount(t) & 1) ? -1 : 1;
            bool valid = true;
            int cur = 0;

            for (int k = 0; k < 6; k++) {
                int b = (t >> k) & 1;
                int xk = (x / p[k]) % 10;
                int yk = (y / p[k]) % 10;
                if (xk > yk) {
                    continue;
                }

                int d = (b == 1) ? (xk - 1) : yk;
                if (d < 0) {
                    valid = false;
                    break;
                }
                cur += d * p[k];
            }

            if (valid) {
                ans += sign * dp[cur];
            }
        }

        std::cout << ans << "\n";
    }
}
