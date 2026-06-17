#include <bits/stdc++.h>

using i64 = long long;

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
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(k);
    std::vector<bool> imp(n);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
        a[i]--;
        imp[a[i]] = true;
    }

    std::vector<std::array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--;
        v--;

        e[i] = {w, u, v};
    }
    rgs::sort(e);

    DSU dsu(n);
    i64 ans = 0;

    if (n == 2) {
        for (auto [w, u, v] : e) {
            if (not dsu.same(u, v)) {
                ans += w;
                dsu.merge(u, v);
            }
        }
        if (dsu.size(0) != n) {
            ans = -1;
        }
        std::cout << ans << "\n";
        return;
    }

    for (auto [w, u, v] : e) {
        if (imp[u] or imp[v]) {
            continue;
        }
        if (not dsu.same(u, v)) {
            ans += w;
            dsu.merge(u, v);
        }
    }

    for (int i = 0; i < n; i++) {
        if (not imp[i] and dsu.size(i) != n - k) {
            std::cout << -1 << "\n";
            return;
        }
    }
    for (auto [w, u, v] : e) {
        if (imp[u] and imp[v]) {
            continue;
        }
        if (not dsu.same(u, v)) {
            assert(imp[u] or imp[v]);
            ans += w;
            dsu.merge(u, v);
        }
    }

    if (dsu.size(0) != n) {
        ans = -1;
    }
    std::cout << ans << "\n";
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

/*
3
5 6 2
1 5
1 2 3
2 5 7
4 2 6
5 4 9
3 4 10
1 3 5
4 4 4
1 2 3 4
1 2 1
2 3 1
3 4 1
4 1 1
3 4 1
1
1 2 10
1 2 100
2 3 1000
3 3 100000

*/