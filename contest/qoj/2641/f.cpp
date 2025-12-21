#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--;
    b--;

    vector<pair<int, int>> edges(m);
    vector adj(n, vector<bool>(n));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        edges[i] = pair(u, v);
        adj[u][v] = adj[v][u] = true;
    }

    if (not adj[a][b]) {
        cout << "Yes\n";
        for (auto [x, y] : edges) {
            if (x == a or x == b) {
                swap(x, y);
            }
            cout << x + 1 << " " << y + 1 << "\n";
        }
        return;
    }
    if (m == n - 1) {
        cout << "No\n";
        return;
    }
    
    queue<int> q;
    
    vector<bool> vis(n);
    vector<int> p(n, -1);

    q.push(a);
    vis[a] = true;

    vector<int> ord(n);
    ranges::iota(ord, 0);
    swap(ord[0], ord[b]);

    vector<pair<int, int>> ans;
    auto addEdge = [&](int x, int y) {
        ans.emplace_back(x, y);
        vis[x] = true;
    };

    while (not q.empty() and ans.empty()) {
        int x = q.front();
        q.pop();

        for (auto y : ord) {
            if (y == p[x] or not adj[x][y]) {
                continue;
            }
            
            if (p[y] != -1) {
                addEdge(x, y);
                while (p[x] != -1) {
                    addEdge(p[x], x);
                    x = p[x];
                }
                while (not vis[y]) {
                    addEdge(y, p[y]);
                    y = p[y];
                }
                break;
            }
            
            p[y] = x;
            q.push(y);
        }
    }

    if (not vis[b]) {
        vis[b] = true;
        ans.emplace_back(b, a);
    }

    cout << "Yes\n";
    for (auto [x, y] : edges) {
        if (vis[x] and vis[y]) {
            continue;
        } else if (vis[x]) {
            swap(x, y);
        }
        cout << x + 1 << " " << y + 1 << "\n";
    }
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
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
}

/*
3
5 4 2 4
1 2
2 3
3 4
4 5
5 7 1 2
1 2
2 3
3 4
4 5
1 5
3 5
1 4
2 1 1 2
1 2

1
6 10 1 6
2 5
4 5
3 6
3 1
4 3
1 2
3 5
1 6
6 5
1 5
*/
