#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, x, y;
    cin >> n >> x >> y;
    
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    // 设 dp[i][j][k] 表示考虑前 i 个菜，吃了 j 个菜，甜度为 k 时，咸度的最小值。
    vector dp(n + 1, vector(n + 1, vector<int>(x + 1, inf)));
    for (int i = 0; i <= n; i++) {
        dp[i][0][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k <= x; k++) {
                if (k - a[i - 1][0] >= 0)
                    dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - 1][k - a[i - 1][0]] + a[i - 1][1]);
                else 
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }

    int res = 0;
    for (int j = n; ~j; j--) {
        for (int k = 0; k <= x; k++) {
            if (dp[n][j][k] <= y) {
                res = max(res, j);
            }
        }
    }
    cout << min(res + 1, n) << endl;

    return 0;
}