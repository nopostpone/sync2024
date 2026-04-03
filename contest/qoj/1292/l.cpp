#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> ask(q);
    for (int i = 0; i < q; i++) {
        int p, a;
        cin >> p >> a;
        p--;
        ask[i] = {p, a};
    }

    vector<int> ans(q);
    for (int maxw = 1; maxw <= 100; maxw++) {
        vector<int> f(n, inf);
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (w[i] <= maxw) {
                que.push(i);
                f[i] = 0;
            }
        }

        while (not que.empty()) {
            int x = que.front();
            que.pop();

            for (auto y : adj[x]) {
                if (f[y] != inf) {
                    continue;
                }
                f[y] = f[x] + 1;
                que.push(y);
            }
        }

        for (int i = 0; i < q; i++) {
            auto [p, a] = ask[i];
            if (a == maxw) {
                ans[i] = f[p] == inf ? -1 : f[p];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}