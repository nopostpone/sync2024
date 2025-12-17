#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int sum = 0;
    for (auto i : b) {
        sum += i;
    }
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }
    sum /= 3;

    vector dp(n + 1, vector(sum + 1, vector<int>(sum + 1, 1e9)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            for (int k = 0; k <= sum; k++) {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + (a[i] != 1));
                if (j >= b[i]) {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - b[i]][k] + (a[i] != 2));
                }
                if (k >= b[i]) {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k - b[i]] + (a[i] != 3));
                }
            }
        }
    }
    cout << (dp[n][sum][sum] == 1e9 ? -1 : dp[n][sum][sum]) << endl;

    return 0;
}