#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 2e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> c(n);

    vector adj(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int u, x, k;
        cin >> u >> x >> k;
        u--;
        c[u] = x;

        while (k--) {
            int v;
            cin >> v;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    /**
     * 0：儿子覆盖自己
     * 1：自己覆盖自己
     * 2：父亲覆盖自己
    */
    vector dp(n, array<int, 3>());
    for (int i = 0; i < n; i++) {
        dp[i][1] = c[i];
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        int cost{inf};
        bool flag{};

        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);

            int t = min(dp[v][0], dp[v][1]);

            // 自己覆盖自己，子节点任意状态皆可
            dp[u][1] += min(t, dp[v][2]);

            // 父亲覆盖自己，子节点不能“父亲覆盖自己”
            dp[u][2] += t;

            // 儿子覆盖自己，需要至少有一个儿子的状态取“自己覆盖自己”，其他子节点也不能“父亲覆盖自己”
            // 如何处理“至少一个”：记录是否取过 + 记录最小差。最终若没有取过就加上最小差。
            dp[u][0] += t;
            if (dp[v][0] < dp[v][1]) {
                cost = min(cost, dp[v][1] - dp[v][0]);
            } else {
                flag = true;
            }
        }
        if (not flag) {
            dp[u][0] += cost;
        }
    };

    dfs(dfs, 0, -1);
    cout << min(dp[0][0], dp[0][1]);

    return 0;
}