#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> revadj;
vector<ll> x;
vector<bool> vis;

void dfs(int u) {
    for (auto [v, w] : adj[u]) {
        if (not vis[v]) {
            vis[v] = true;
            x[v] = x[u] + w;
            dfs(v);
        }
    }
    for (auto [v, w] : revadj[u]) {
        if (not vis[v]) {
            vis[v] = true;
            x[v] = x[u] - w;
            dfs(v);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    x.assign(n, 0);
    adj.assign(n, {});
    revadj.assign(n, {});
    vis.assign(n, false);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w});
        revadj[v].push_back({u, w});
    }

    for (int i = 0; i < n; i++) {
        if (not vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }

    for (auto i : x) {
        cout << i << " ";
    }

    return 0;
}