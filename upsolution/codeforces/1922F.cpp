#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector dp(n, vector(n, vector(x, inf))); // [l, r] 全弄成 v 的最小操作次数
    auto g = dp;                             // [l, r] 不出现 v 的最小操作次数

    for (int i = 0; i < n; i++) { // 对长度为 1 的区间初始化
        dp[i][i].assign(x, 1);
        g[i][i].assign(x, 0);

        dp[i][i][a[i]] = 0;
        g[i][i][a[i]] = 1;
    }

    for (int len = 2; len <= n; len++) {        // 长度
        for (int l = 0; l + len - 1 < n; l++) { // 左端点
            int r = l + len - 1;
            int res = inf;

            for (int v = 0; v < x; v++) {     // 值域
                for (int m = l; m < r; m++) { // 先枚举中间的点转移：g[l][r] <- g[l][m] + g[m + 1][r]
                    g[l][r][v] = min(g[l][r][v], g[l][m][v] + g[m + 1][r][v]);
                }
                res = min(res, g[l][r][v] + 1); // 记录这个东西的最小值 + 1，意思是不出现 v 之后多操作一次。
            }

            for (int v = 0; v < x; v++) {
                g[l][r][v] = min(g[l][r][v], res);              // 不出现某个数之后多操作一次，肯定能不出现 v。
                dp[l][r][v] = min(dp[l][r][v], g[l][r][v] + 1); // dp[l][r][v] <- g[l][r][v] + 1
                for (int m = l; m < r; m++) {
                    dp[l][r][v] = min(dp[l][r][v], dp[l][m][v] + dp[m + 1][r][v]);
                }
            }
        }
    }

    cout << *min_element(dp[0][n - 1].begin(), dp[0][n - 1].end()) << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}