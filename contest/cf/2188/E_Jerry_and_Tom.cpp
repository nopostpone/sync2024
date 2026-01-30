#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> to(n);
    for (int i = 0; i < n - 1; i++) {
        to[i] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        to[u] = max(to[u], v);
    }

    vector<int> dep(n);
    for (int i = n - 2; i >= 0; i--) {
        dep[i] = dep[to[i]] + 1;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[to[i]].push_back(i);
    }

    i64 ans = 0;

    vector<map<int, int>> f(n);
    vector<int> siz(n);

    for (int x = 0; x < n; x++) {
        f[x][dep[x]] += 1;
        siz[x] = 1;

        for (auto y : adj[x]) {
            f[y][dep[x]] += 0;
            if (f[y].size() > f[x].size()) {
                swap(f[x], f[y]);
                swap(siz[x], siz[y]);
            }

            auto itx = f[x].begin();
            auto ity = f[y].begin();
            int cx = 0, cy = 0;

            while (ity != f[y].end()) {
                ans += i64(itx->first - dep[x]) * itx->second * (siz[y] - cy);
                ans += i64(ity->first - dep[x]) * ity->second * (siz[x] - cx);
                cx += itx->second;
                cy += ity->second;
                itx->second += ity->second;
                itx++;
                ity++;
            }

            siz[x] += siz[y];
            f[y].clear();
        }
    }

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