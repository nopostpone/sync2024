#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n);
    int ans{1};

    auto dfs = [&](auto &&self, int u, int fa) -> void {
        int siz = adj[u].size() - 2;
        dp[u] = siz;
        ans = max(ans, siz + 2);
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            ans = max(ans, dp[u] + dp[v] + 2);
            dp[u] = max(dp[u], siz + dp[v]);
        }
    };

    dfs(dfs, 0, -1);

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}