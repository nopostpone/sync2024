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

constexpr int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    i64 ans = 0;

    vector<array<int, 3>> edges;

    vector<int> deg(2 * n - 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        ans += w;
        edges.push_back({w, u, v});

        deg[u] ^= 1;
        deg[v] ^= 1;
    }
    
    int tot = n;

    vector<int> dp(2 * n - 1, inf);
    DSU dsu(2 * n - 1);

    vector<vector<int>> adj(2 * n - 1);
    for (auto [w, u, v] : edges) {
        u = dsu.find(u);
        v = dsu.find(v);
        if (u == v) {
            dp[u] = min(dp[u], w);
            continue;
        }
        dsu.merge(tot, u);
        dsu.merge(tot, v);

        adj[tot] = {u, v};
        dp[tot] = w;

        tot++;
    }

    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            dp[y] = min(dp[y], dp[x]);
            self(y);
            deg[x] += deg[y];
        }

        if (deg[x] >= 2) {
            deg[x] -= 2;
            ans += dp[x];
        }
    } (tot - 1);

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
