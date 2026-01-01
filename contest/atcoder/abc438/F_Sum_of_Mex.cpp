#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
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
                std::swap(v, adj[u][0]);
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
    // [u, v]
    auto getPath(int u, int v) {
        std::vector<std::pair<int, int>> ret;
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
        return std::move(ret);
    }
    // [u, v)
    std::pair<int, int> getTree(int u) {
        return pair(in[u], out[u]);
    }
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        int d = dep[u] - k;
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        return seq[in[u] - dep[u] + d];
    }
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    HLD t(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        t.addEdge(u, v);
    }
    t.work();

    i64 ans = 1ll * n * (n + 1) / 2;
    for (auto x : t.adj[0]) {
        ans -= 1ll * t.siz[x] * (t.siz[x] + 1) / 2;
    }

    int x = 0, y = 0;
    for (int k = 1; k < n; k++) {
        if (t.dist(x, k) + t.dist(x, y) == t.dist(y, k)) {
            x = k;
        } else if (t.dist(y, k) + t.dist(x, y) == t.dist(x, k)) {
            y = k;
        } else if (t.dist(x, k) + t.dist(y, k) == t.dist(x, y)) {

        } else {
            break;
        }

        ans += 1ll * t.rootedSize(x, y) * t.rootedSize(y, x);
    }
    cout << ans << "\n";


    return 0;
}