#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

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
    std::cin >> n >> m;
    
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    DSU dsu(n);
    int p = -1, q = -1;
    std::vector<std::vector<int>> adj(n);
    std::vector<std::pair<int, int>> e0, e1;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        (x[u] == x[v] ? e0 : e1).emplace_back(u, v);
    }
    for (auto [u, v] : e0) {
        dsu.merge(u, v);
    }
    for (auto [u, v] : e1) {
        if (not dsu.merge(u, v) and p == -1) {
            std::tie(p, q) = std::minmax(u, v);
        }
    }
    if (p == -1 or m == n - 1) {
        std::cout << "No\n";
        return;
    }

    std::queue<int> que;
    que.push(p);

    std::vector<int> f(n, -1);
    f[p] = 0;

    while (not que.empty()) {
        auto x = que.front();
        que.pop();

        for (auto y : adj[x]) {
            if (x == p and y == q) {
                continue;
            }
            if (f[y] == -1) {
                f[y] = f[x] + 1;
                que.push(y);
            }
        }
    }

    std::cout << "Yes\n";
    for (int x = 0; x < n; x++) {
        for (auto y : adj[x]) {
            if (x > y) {
                continue;
            }
            if ((f[x] <= f[y]) ^ (x == p and y == q)) {
                std::cout << y + 1 << " " << x + 1 << "\n";
            } else {
                std::cout << x + 1 << " " << y + 1 << "\n";
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}