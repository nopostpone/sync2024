#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr int dlog(int x) { return std::log2(x); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;

    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dep(n);
    vector parent(n, vector<int>(20));

    auto dfs = [&](auto &&self, int u) -> void {
        for (int i = 1; i < 20; i++) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
        }
        for (auto v : adj[u]) {
            if (v != parent[u][0]) {
                parent[v][0] = u;
                dep[v] = dep[u] + 1;

                self(self, v);
            }
        }
    };
    parent[s][0] = s;
    dfs(dfs, s);

    auto lca = [&](int u, int v) -> int {
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        while (dep[u] > dep[v]) {
            u = parent[u][dlog(dep[u] - dep[v])];
        }
        if (u == v)
            return u;

        for (int i = dlog(dep[u]); ~i; i--) {
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    };

    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << lca(x, y) + 1 << endl;
    }    
    return 0;
}