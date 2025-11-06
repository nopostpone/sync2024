#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    const int n = a.size();
    const int m = b.size();

    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + (a[i - 1] != c[i - 1]);
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] + (b[j - 1] != c[j - 1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]),
                           dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
        }
    }

    cout << dp[n][m] << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}