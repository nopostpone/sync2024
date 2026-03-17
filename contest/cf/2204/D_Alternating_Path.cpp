#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(2 * n), g(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dsu.merge(u, v + n);
        dsu.merge(u + n, v);
        g.merge(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;

    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (dsu.same(i, i + n) or vis[i]) {
            continue;
        }
        int cnt[2] {};
        [&](this auto &&self, int x, int t) -> void {
            vis[x] = true;
            cnt[t]++;

            for (auto y : adj[x]) {
                if (vis[y]) {
                    continue;
                }
                self(y, t ^ 1);
            }
        } (i, 0);

        ans += max(cnt[0], cnt[1]);
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
}