#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> in(n), siz(n);
    int tot = 0;

    auto dfs = [&](auto &&self, int x, int p) -> void {
        in[x] = tot++;
        siz[x] = 1;

        if (p != -1) {
            adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
        }
        if (adj[x].empty()) {
            return;
        }
        for (auto y : adj[x]) {
            self(self, y, x);
            siz[x] += siz[y];
        }
        sort(adj[x].begin(), adj[x].end(),
            [&](int i, int j) {
                return c[i] < c[j];
            });
        int mn1 = c[adj[x][0]];
        int mn2 = c[adj[x][1]];
        c[x] = min(c[x], mn1 + mn2);
    };
    dfs(dfs, 0, -1);

    vector<i64> f(n);
    auto dfs2 = [&](auto &&self, int x) -> void {
        if (adj[x].empty()) {
            return;
        }
        int mn1 = c[adj[x][0]];
        int mn2 = c[adj[x][1]];
        for (auto y : adj[x]) {
            if (c[y] == mn1) {
                f[y] = f[x] + mn2;
            } else {
                f[y] = f[x] + mn1;
            }
            self(self, y);
        }
    };
    dfs2(dfs2, 0);

    auto check = [&](int anc, int son) {
        return in[anc] <= in[son] and in[son] < in[anc] + siz[anc];
    };

    for (int _ = 0; _ < m; _++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (x == y) {
            cout << 0 << "\n";
            continue;
        }
        if (not check(y, x)) {
            cout << -1 << "\n";
            continue;
        }

        cout << f[x] - f[y] << "\n";
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
3
5 5
1 2 3 4 5
1 2
1 3
2 4
2 5
3 1
2 1
4 1
5 1
5 2
5 5
1 5 1 1 1
1 2
1 3
2 4
2 5
3 1
2 1
4 1
5 1
2 5
6 5
9 9 8 2 4 4
1 2
1 3
1 4
1 5
1 6
2 1
3 1
4 1
5 1
6 1
*/