#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int P = 998244353;

constexpr int N = 2000;

int dp[2 * N][N + 1][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    n *= 2;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> siz(n);

    auto dfs = [&](auto &&self, int x, int p) -> void {
        dp[x][0][0] = 1;
        siz[x] = 1;

        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }

            self(self, y, x);
            for (int i = siz[x] / 2; i >= 0; i--) {
                for (int j = 0; j <= siz[y] / 2; j++) {
                    if (j) {
                        for (int k = 0; k < 2; k++) {
                            dp[x][i + j][k] = (dp[x][i + j][k] + i64(dp[y][j][0] + dp[y][j][1]) * dp[x][i][k]) % P;
                        }
                    }
                    dp[x][i + j + 1][1] = (dp[x][i + j + 1][1] + i64(dp[y][j][0]) * dp[x][i][0]) % P;
                }
            }
            siz[x] += siz[y];
        }
    };
    dfs(dfs, 0, -1);

    vector<int> f(n / 2 + 1);
    f[0] = 1;
    for (int i = 1; i <= n / 2; i++) {
        f[i] = i64(f[i - 1]) * (2 * i - 1) % P;
    }

    int ans = 0;
    for (int i = 0; i <= n / 2; i++) {
        int res = i64(dp[0][i][0] + dp[0][i][1]) * f[n / 2 - i] % P;

        ans = (ans + i64(i % 2 ? P - 1 : 1) * res) % P;
    }

    cout << ans << "\n";
}