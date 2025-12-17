#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr int inf = 2e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector dis(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dis[i][j];
        }
    }
    
    vector dp(1 << n, vector<int>(n, inf));
    dp[1][0] = 0;
    for (int S = 3; S < (1 << n); S += 2) { 
        for (int v = 0; v < n; v++) {
            if ((S >> v) & 1) {
                for (int u = 0; u < n; u++) {
                    dp[S][v] = min(dp[S][v], dp[S - (1 << v)][u] + dis[u][v]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;

    return 0;
}