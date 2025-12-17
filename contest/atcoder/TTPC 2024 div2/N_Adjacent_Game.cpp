#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
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

    vector<int> siz(n, 1), dep(n);

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            dep[v] = dep[u] + 1;
            self(self, v, u);
            siz[u] += siz[v];
        }
    };
    dfs(dfs, 0, -1);

    for (int i = 0; i < n; i++) {
        
    }
    
    
    return 0;
}