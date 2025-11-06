#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    vector g(n + 1, vector<int>());
    bitset<10000> vis(0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        vis[u] = 1;
    }    

    vector dp(n + 1, vector<int>(2));

    for (int i = 1; i <= n; i++) {
        dp[i][1] = r[i];
    }

    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : g[u]) {
            dfs(v);
            dp[u][1] += dp[v][0];
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
    };

    int rt;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            cout << max(dp[i][0], dp[i][1]) << endl;
            break;
        }
    }

    return 0;
}