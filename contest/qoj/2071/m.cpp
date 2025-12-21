#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {w, u, v};
    }
    ranges::sort(edges);
    
    DSU dsu(n);

    vector<vector<pair<int, int>>> adj(n);

    for (auto [w, u, v] : edges) {
        if (dsu.merge(u, v)) {
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
    }
    
    vector<int> dep(n);
    vector<array<int, 20>> p(n);

    vector<i64> f(n);

    [&](this auto &&self, int x) -> void {
        for (int i = 1; i < 20; i++) {
            p[x][i] = p[p[x][i - 1]][i - 1];
        }
        for (auto [y, w] : adj[x]) {
            if (y == p[x][0]) {
                continue;
            }
            p[y][0] = x;
            f[y] = f[x] + w;
            dep[y] = dep[x] + 1;
            self(y);
        }
    } (0);

    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        while (dep[x] > dep[y]) {
            x = p[x][__lg(dep[x] - dep[y])];
        }
        if (x == y) {
            return x;
        }
        for (int i = __lg(dep[x]); i >= 0; i--) {
            if (p[x][i] != p[y][i]) {
                x = p[x][i];
                y = p[y][i];
            }
        }
        return p[x][0];
    };

    auto dis = [&](int x, int y) {
        int z = lca(x, y);
        return f[x] + f[y] - f[z] * 2;
    };

    bool ok = true;
    for (auto [w, u, v] : edges) {
        if (dis(u, v) > w) {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
}


/*
3 3
1 2 3
2 3 4
3 1 100

3 3
1 2 3
2 3 4
3 1 2

*/