#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    vector a(n + 1, vector<int>(n + 1));

    for (int x, y, k; cin >> x >> y >> k;) {
        a[x][y] = k;
    }

    vector dp(n + 1, vector(n + 1, vector(n + 1, vector<int>(n + 1))));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    dp[i][j][k][l] = max({dp[i - 1][j][k - 1][l],
                                          dp[i - 1][j][k][l - 1],
                                          dp[i][j - 1][k - 1][l],
                                          dp[i][j - 1][k][l - 1]}) +
                                     a[i][j] + a[k][l];
                    if (i == k && l == j) {
                        dp[i][j][k][l] -= a[i][j];
                    }
                }
            }
        }
    }

    cout << dp[n][n][n][n];

    return 0;
}