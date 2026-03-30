#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
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
    
    vector<vector<pair<int, int>>> ask(n);
    for (int i = 0; i < q; i++) {
        int x, d;
        cin >> x >> d;
        x--;
        ask[x].emplace_back(d, i);
    }

    vector<int> siz(n), dep(n);
    [&](this auto &&self, int x, int p) -> void {
        if (p != -1) {
            adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
        }
        siz[x] = 1;
        for (auto &y : adj[x]) {
            dep[y] = dep[x] + 1;
            self(y, x);
            siz[x] += siz[y];
            if (siz[y] > siz[adj[x][0]]) {
                swap(adj[x][0], y);
            }
        }
    } (0, -1);

    vector<i64> f(n + 1);
    vector<i64> ans(q);

    auto add = [&](auto &&self, int x, int t) -> void {
        f[dep[x]] += t * a[x];
        for (auto y : adj[x]) {
            self(self, y, t);
        }
    };
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y != adj[x][0]) {
                self(y);
                add(add, y, -1);
            }
        }
        if (not adj[x].empty()) {
            self(adj[x][0]);
            for (auto y : adj[x]) {
                if (y != adj[x][0]) {
                    add(add, y, 1);
                }
            }
        }
        f[dep[x]] += a[x];
        for (auto [d, i] : ask[x]) {
            ans[i] = f[dep[x] + d];
        }

    } (0);
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}