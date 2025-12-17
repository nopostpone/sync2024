#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] |= dp[i][j] | dp[i][m];
            }
            if (s[i] == t[0]) {
                dp[i + 1][1] |= dp[i][j];
            }
        }
    }

    cout << (dp[n][m] ? "Yes" : "No");
    
    return 0;
}