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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        edges[i] = {l, a, b};
    }

    ranges::sort(edges);

    vector<vector<int>> adj(2 * n - 1);
    DSU dsu(2 * n - 1);

    int tot = n;

    vector<int> f(2 * n - 1, 1e9);

    for (auto [w, u, v] : edges) {
        u = dsu.find(u);
        v = dsu.find(v);
        if (u != v) {
            dsu.merge(tot, u);
            dsu.merge(tot, v);
            f[tot] = w;
            adj[tot] = {u, v};
            tot++;
        }
    }
    adj.resize(tot + 1);

    const int logt = __lg(tot + 1);
    vector p(logt + 1, vector<int>(tot + 1));
    for (int i = 0; i < tot; i++) {
        if (dsu.find(i) == i) {
            adj[tot].push_back(i);
        }
    }

    vector<int> dep(tot + 1);

    [&](this auto &&self, int x) -> void {
        for (int i = 0; i < logt; i++) {
            p[i + 1][x] = p[i][p[i][x]];
        }
        for (auto y : adj[x]) {
            p[0][y] = x;
            dep[y] = dep[x] + 1;
            self(y);
        }
    } (tot);

    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        while (dep[x] > dep[y]) {
            x = p[__lg(dep[x] - dep[y])][x];
        }
        if (x == y) {
            return x;
        }

        for (int i = __lg(dep[x]); i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        return p[0][x];
    };

    int q;
    cin >> q;

    for (int _ = 0; _ < q; _++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        int l = lca(x, y);
        if (l == tot) {
            cout << "impossible\n";
        } else {
            cout << f[l] << "\n";
        }
    }


    return 0;
}