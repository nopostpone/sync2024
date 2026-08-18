#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

double F[101][101];

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<double> dp(n + 1);
    dp[0] = 1;

    for (int _ = 0; _ < m; _++) {
        std::vector<double> ndp(n + 1);
        for (int i = 0; i <= n; i++) {
            int b = std::min(i, n - k);
            for (int j = b; j <= b + k; j++) {
                ndp[j] += dp[i] * F[k][j - b];
            }
        }
        dp = std::move(ndp);

        // for (int i = 0; i <= n; i++) {
        //     std::cout << dp[i] << " \n"[i == n];
        // }
    }

    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i] * i;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(3);

    F[1][0] = F[1][1] = 0.5;
    for (int i = 2; i <= 100; i++) {
        F[i][0] = F[i - 1][0] / 2;
        for (int j = 0; j < i; j++) {
            F[i][j + 1] = F[i][j] * (i - j) / (j + 1);
        }
        // for (int j = 0; j <= i; j++) {
        //     std::cout << F[i][j] << " \n"[j == i];
        // }


    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}