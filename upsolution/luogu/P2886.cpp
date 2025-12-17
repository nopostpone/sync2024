#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, t, S, E;
    cin >> n >> t >> S >> E;

    unordered_map<int, int> f;
    int cur = 0;

    vector<array<int, 3>> edges(t);
    for (int i = 0; i < t; i++) {
        int u, v, w;
        cin >> w >> u >> v;
        if (not f.contains(u)) {
            f[u] = cur++;
        }
        if (not f.contains(v)) {
            f[v] = cur++;
        }
        edges[i] = {f[u], f[v], w};
    }
    S = f[S];
    E = f[E];

    vector dp(20, vector(cur, vector(cur, inf)));
    for (auto [u, v, w] : edges) {
        dp[0][u][v] = dp[0][v][u] = w;
    }
    for (int i = 1; i < 20; i++) {
        for (int u = 0; u < cur; u++) {
            for (int v = 0; v < cur; v++) {
                for (int k = 0; k < cur; k++) {
                    dp[i][u][v] = min(dp[i][u][v], dp[i - 1][u][k] + dp[i - 1][k][v]);
                }
            }
        }
    }

    vector dp2(cur, inf);
    dp2[S] = 0;
    for (int i = 0; n; i++, n /= 2) {
        if (n % 2 == 0) {
            continue;
        }
        vector ndp2(cur, inf);
        for (int j = 0; j < cur; j++) {
            for (int k = 0; k < cur; k++) {
                ndp2[j] = min(ndp2[j], dp2[k] + dp[i][j][k]);
            }
        }
        dp2 = ndp2;
    }
    cout << dp2[E] << "\n";

    return 0;
}