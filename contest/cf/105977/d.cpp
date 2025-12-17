#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    vector<pair<int, int>> edges(n - 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
        edges.emplace_back(u, v);
    }
    for (auto &[u, v] : edges) {
        if (deg[u] > deg[v]) {
            swap(u, v);
        }

        
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
6
1
1
3
1 2 2
5
1 3 4 5 2
7
1 2 3 5 6 7 4
9
9 9 8 2 4 4 3 5 3
9
4 4 9 2 9 5 8 3 3
*/