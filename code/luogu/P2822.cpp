#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int t, k;
    cin >> t >> k;

    constexpr int N = 2e3;

    vector dp(N + 1, vector<int>(N + 1, k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % k;
        }
    }

    vector pre(N + 1, vector<int>(N + 1));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            pre[i][j] = (dp[i][j] == 0);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    while (t--) {
        int n, m;
        cin >> n >> m;
        m = min(n - 1, m);
        cout << pre[n - 1][m] << "\n";
    }

    return 0;
}
