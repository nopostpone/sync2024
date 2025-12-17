#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj[2];
    for (int i = 0; i < 2; i++) {
        adj[i].assign(n, {});
    }
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;

        adj[t][u].push_back(v);
        adj[t][v].push_back(u);
    }
    for (int x = 0; x < n; x++) {
        ranges::sort(adj[0][x]);
        ranges::sort(adj[1][x]);
    }

    int ans = n;
    {
        vector<bool> vis(n);
        for (int x = 0; x < n; x++) {
            for (auto y : adj[0][x]) {
                if (y < x) {
                    continue;
                }
                vis[y] = true;
            }
            for (auto y : adj[1][x]) {
                ans += vis[y];
            }
            for (auto y : adj[0][x]) {
                if (y < x) {
                    continue;
                }
                vis[y] = false;
            }
        }
    }
    {
        for (int x = 0; x < n; x++) {
            vector<int> s[2];
            for (int t = 0; t < 2; t++) {
                for (auto y : adj[t][x]) {
                    s[t].push_back(y);
                }
            }
            for (auto i : s[0]) {
                for (auto j : s[1]) {
                    ans += binary_search(adj[0][i].begin(), adj[0][i].end(), j) and
                        binary_search(adj[1][i].begin(), adj[1][i].end(), j);
                }
            }
        }
    }
    {
        vector<bool> vis(n);
        for (int x = 0; x < n; x++) {
            if (vis[x]) {
                continue;
            }
            set<int> s[2] {{x}, {x}};
            for (int t = 0; t < 2; t++) {
                [&](this auto &&self, int x) {
                    if (s[t].size() > 4) {
                        return;
                    }
                    for (auto y : adj[t][x]) {
                        if (s[t].contains(y)) {
                            continue;
                        }
                        s[t].insert(y);
                        self(y);
                    }

                } (x);
            }
            if (s[0].size() == 4 and s[0] == s[1]) {
                ans++;
                for (auto x : s[0]) {
                    vis[x] = true;
                }
            }
        }
    }

    cout << ans << "\n";
}

/*
3 4
1 2 0
1 3 1
2 3 0
2 3 1

4 6
1 2 0
2 3 0
3 4 0
1 4 1
2 4 1
1 3 1
*/