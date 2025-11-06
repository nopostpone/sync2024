#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const int logn;

    const Cmp cmp = Cmp();
    std::vector<std::vector<T>> jump;

    constexpr RMQ(const std::vector<T> &a)
        : n{a.size()}, logn{std::__lg(n)}, jump(logn + 1) {

        jump[0] = a;

        for (int j = 1; j <= logn; j++) {
            jump[j].resize(n - (1 << j) + 1);
        }

        for (int j = 0; j < logn; j++) {
            const int limit = n - (1 << (j + 1));
            for (int i = 0; i <= limit; i++) {
                jump[j + 1][i] = std::min(jump[j][i], jump[j][i + (1 << j)], cmp);
            }
        }
    }

    constexpr T operator()(int l, int r) const {
        int log = std::__lg(r - l);
        return std::min(jump[log][l], jump[log][r - (1 << log)], cmp);
    }
};

struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> adj;
    int cur;

    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }

        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
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
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    bool isAncester(int fa, int son) {
        return in[fa] <= in[son] && in[son] < out[fa];
    }
    auto getPath(int u, int v) {
        vector<pair<int, int>> ret;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                ret.push_back({in[top[u]], in[u]});
                u = parent[top[u]];
            } else {
                ret.push_back({in[top[v]], in[v]});
                v = parent[top[v]];
            }
        }
        if (dep[u] > dep[v]) {
            ret.push_back({in[v], in[u]});
        } else {
            ret.push_back({in[u], in[v]});
        }
        return ret;
    }
    pair<int, int> getTree(int u) {
        return make_pair(in[u], out[u]);
    }
};

unordered_map<ll, int> edges;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    HLD hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        hld.addEdge(u, v);
        edges[1ll * u * n + v] = w;
        edges[1ll * v * n + u] = w;
    }
    hld.work();

    vector<int> init(n, 2e9);
    for (int i = 0; i < n; i++) {
        int now = hld.seq[i];
        int fa = hld.parent[now];
        if (fa != -1) {
            init[i] = edges[1ll * now * n + fa];
        }
    }
    RMQ<int> rmq(init);

    auto cmp = [&hld](int x, int y) { return hld.in[x] < hld.in[y]; };
    auto getDis = [&](int x, int y) {
        int res = 2e9;
        for (auto [u, v] : hld.getPath(x, y)) {
            res = min(res, rmq(u, v + 1));
        }
        return res;
    };

    int m;
    
    vector<bool> imp(n);
    vector vt(n, vector<pair<int, ll>>());
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
            vt[l].push_back({v[i], getDis(v[i], l)});
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