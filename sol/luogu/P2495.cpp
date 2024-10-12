#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct TreeRMQ {
    int n;
    vector<int> siz, top, dep, dfn, dis, parent, A;
    vector<vector<int>> adj;
    unordered_map<ll, int> edges;
    int cur;

    TreeRMQ() {}
    TreeRMQ(int _n) {
        init(_n);
    }
    void init(int _n) {
        n = _n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        dfn.resize(n);
        dis.resize(n);
        A.resize(n);
        parent.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v, int w) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[1ll * u * n + v] = w;
        edges[1ll * v * n + u] = w;
    }
    void work(int root = 0) {
        top[root] = root;
        parent[root] = -1;
        dis[root] = 2e9;
        dfs1(root);
        dfs2(root);
        
        for (int i = 0; i < n; i++) {
            A[dfn[i]] = dis[i];
        }
        rmqinit();
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        siz[u] = 1;
        for (int &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dis[v] = edges[1ll * u * n + v];
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        dfn[u] = cur++;
        for (int v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    vector<vector<int>> jump;

    void rmqinit() {
        jump.assign(n + 1, {});

        int logn = std::__lg(n);
        jump[0] = A;
        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }
        for (int j = 0; j < logn; j++) {
            const int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = min(jump[j][i], jump[j][i + (1 << j)]);
            }
        }
    }
    int rangeQuery(int l, int r) {
        assert(r - l >= 1);
        int t = std::__lg(r - l);
        return min(jump[t][l], jump[t][r - (1 << t)]);
    }
    int pathQuery(int u, int v) {
        int res = 2e9;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                res = min(res, rangeQuery(dfn[top[u]], dfn[u] + 1));
                u = parent[top[u]];
            } else {
                res = min(res, rangeQuery(dfn[top[v]], dfn[v] + 1));
                v = parent[top[v]];
            }
        }
        if (dep[u] - dep[v] > 0) {
            res = min(res, rangeQuery(dfn[v] + 1, dfn[u] + 1));
        } else if (dep[v] - dep[u] > 0) {
            res = min(res, rangeQuery(dfn[u] + 1, dfn[v] + 1));
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    TreeRMQ hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        hld.addEdge(u, v, w);
    }
    hld.work();

    auto cmp = [&hld](int x, int y) { return hld.dfn[x] < hld.dfn[y]; };

    int m;
    
    vector<bool> imp(n);
    vector vt(n, vector<pair<int, ll>>());
    // vector<vector<pair<int, ll>>> vt;
    vector<ll> dp(n);

    for (cin >> m; m--;) {
        int t;
        cin >> t;

        vector<int> v(t + 1);
        for (int i = 1; i <= t; i++) {
            cin >> v[i];
            v[i]--;
            imp[v[i]] = true;
        }
        ranges::sort(v, cmp);

        for (int i = 1; i <= t; i++) {
            v.push_back(hld.lca(v[i - 1], v[i]));
        }
        ranges::sort(v, cmp);
        v.erase(unique(v.begin(), v.end()), v.end());

        for (int i = 1; i < (int)v.size(); i++) {
            int l = hld.lca(v[i - 1], v[i]);
            vt[l].push_back({v[i], hld.pathQuery(v[i], l)});
        }

        auto solve = [&](auto &&self, int u) -> void {
            dp[u] = 0;
            for (auto [v, w] : vt[u]) {
                self(self, v);
                if (imp[v]) {
                    dp[u] += w;
                } else {
                    dp[u] += min<ll>(dp[v], w);
                }
            }
        };
        solve(solve, 0);
        cout << dp[0] << "\n";

        auto clr = [&](auto &&self, int u) -> void {
            imp[u] = false;
            for (auto &[v, _] : vt[u]) {
                self(self, v);
            }
            vt[u].clear();
        };
        clr(clr, 0);
    }
    

    return 0;
}