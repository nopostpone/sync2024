#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    std::string a, b;
    std::cin >> a >> b;

    int n = a.size(), m = b.size();

    std::vector<int> sa(n + 1), sb(m + 1);
    for (int i = 0; i < n; i++) {
        sa[i + 1] = (sa[i] + a[i] - '0') % 10;
    }
    for (int i = 0; i < m; i++) {
        sb[i + 1] = (sb[i] + b[i] - '0') % 10;
    }
    if (sa.back() != sb.back()) {
        std::cout << -1 << "\n";
        return;
    }

    std::vector dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sa[i] == sb[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    std::cout << dp[n][m] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}