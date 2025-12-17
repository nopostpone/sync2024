#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using p32 = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<p32>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> dp(n), dep(n);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        for (auto [y, z] : adj[x]) {
            if (y == p) {
                continue;
            }
            dep[y] = dep[x] + 1;
            dp[y] = z - dp[x];
            self(self, y, x);
        }
    };

    dfs(dfs, 0, -1);

    int l = 0, r = 1e9;
    for (int i = 1; i < n; i++) {
        if (dep[i] % 2) {
            l = max(l, dp[i] - (int)1e9);
            r = min(r, dp[i] - 1);
        } else {
            l = max(l, 1 - dp[i]);
            r = min(r, (int)1e9 - dp[i]);
        }
    }

    if (l > r) {
        cout << "NO\n";
        std::exit(0);
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        int ans = dp[i] + (dep[i] % 2 ? -l : l);
        cout << ans << " \n"[i == n - 1];
    }

    return 0;
}

/*
5
1 2 5
1 3 4
2 5 7
3 4 2

4
1 2 5
2 3 9
3 4 4
*/