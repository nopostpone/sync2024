#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i]--;
    }

    std::vector<int> pa(n + 1, n), pb(n + 1, n);
    std::vector<int> dp(n + 1, n);

    i64 ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        pa[a[i]] = i;
        pb[b[i]] = i;

        if (a[i] == b[i]) {
            int x = a[i] + 1;
            if (pa[x] == pb[x]) {
                dp[i] = dp[pa[x]];
            } else {
                dp[i] = std::min(pa[x], pb[x]);
            }
        }

        ans += (pa[0] != pb[0] ? std::min(pa[0], pb[0]) : dp[pa[0]]) - i;
    }

    std::cout << ans << "\n";
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
