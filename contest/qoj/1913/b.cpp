#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    auto cmp = [&](int i, int j) {
        return q[i] < q[j];
    };
    for (int x = 0; x < n; x++) {
        ranges::sort(adj[x], cmp);
    }

    int i = 0;

    vector<pair<int, int>> add;
    auto dfs = [&](auto &&self, int x) -> void {
        i++;
        while (i < n) {
            int y = p[i];
            if (adj[x].empty() or q[adj[x].back()] < i) {
                return;
            }
            if (not binary_search(adj[x].begin(), adj[x].end(), y, cmp)) {
                add.emplace_back(x, y);
            }
            self(self, y);
        }
    };

    while (i < n) {
        dfs(dfs, p[i]);
    }

    cout << add.size() << "\n";
    for (auto [x, y] : add) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

/*
6 6
1 3
1 4
2 3
3 4
3 6
5 6
1 2 3 4 5 6
*/