#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2000;
int dp[N + 1][N + 1];

constexpr int P = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("1.out", "w", stdout);

    int i, n, m;

    for (i = N; i > 0; i--) {
        dp[1][i] += 1;
        for (n = 0; n < N; n++) {
            for (m = 0; m <= N; m++) {
                dp[n + 1][m] += dp[n][m];
                if (dp[n + 1][m] >= P) {
                    dp[n + 1][m] -= P;
                }
            }
            for (m = 0; m <= N - i; m++) {
                dp[n + 1][m + i] += dp[n][m];
                if (dp[n + 1][m + i] >= P) {
                    dp[n + 1][m + i] -= P;
                }
            }
        }
    }

    cout << "{";

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << dp[i][j] << ",";
        }
    }
    cout << "}";

    return 0;
}