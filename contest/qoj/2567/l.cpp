#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
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

    vector<int> siz(n);
    [&](this auto &&self, int x, int p) -> void {
        siz[x] = 1;
        if (p != -1) {
            adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
        }
        for (auto &y : adj[x]) {
            self(y, x);
            siz[x] += siz[y];
            if (siz[y] > siz[adj[x][0]]) {
                swap(adj[x][0], y);
            }
        }
    } (0, -1);

    vector<int> f(n + 1);
    int ca0 = 0, ca1 = 0;
    int cb0 = 0, cb1 = 0;
    auto addv = [&](int v, int t) {
        if (f[v] < 0) {
            cb1 -= -f[v];
        } else {
            ca1 -= f[v];
        }
        f[v] += t;
        if (f[v] < 0) {
            cb1 += -f[v];
        } else {
            ca1 += f[v];
        }
    };
    auto addp = [&](int p, int t) {
        if (a[p]) {
            addv(a[p], t);
        } else {
            ca0 += t;
        }
        if (b[p]) {
            addv(b[p], -t);
        } else {
            cb0 += t;
        }
    };
    auto dfs = [&](this auto &&self, int x, int t) -> void {
        addp(x, t);
        for (auto y : adj[x]) {
            self(y, t);
        }
    };

    string ans(n, '0');
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y != adj[x][0]) {
                self(y);
                dfs(y, -1);
            }
        }
        if (not adj[x].empty()) {
            self(adj[x][0]);
            for (auto y : adj[x]) {
                if (y != adj[x][0]) {
                    dfs(y, 1);
                }
            }
        }
        addp(x, 1);
        if (ca0 >= cb1 and cb0 >= ca1) {
            ans[x] = '1';
        }
    } (0);

    cout << ans << "\n";
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
6
1 5 0 3 4 0
0 3 4 5 2 0
1 2
2 3
2 4
1 5
5 6
5
2 2 3 0 4
4 1 4 2 0
1 2
2 3
3 4
4 5
3
1 2 3
3 2 1
1 2
2 3
*/