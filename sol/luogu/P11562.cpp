#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dp(n);

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            dp[v] = dp[u] + (a[u] ^ a[v]);
            self(self, v, u);
        }
    };
    dp[0] = a[0];
    dfs(dfs, 0, -1);

    int p = max_element(dp.begin(), dp.end()) - dp.begin();
    dp[p] = a[p];
    dfs(dfs, p, -1);

    p = max_element(dp.begin(), dp.end()) - dp.begin();
    cout << (dp[p] + 1) / 2 << endl;
    return 0;
}