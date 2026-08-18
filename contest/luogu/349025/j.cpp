#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int logn = std::__lg(n);

    std::vector<int> dep(n);
    std::vector p(logn + 1, std::vector<int>(n));
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[0][x]) {
                continue;
            }
            p[0][y] = x;
            dep[y] = dep[x] + 1;
            self(y);
        }
    } (0);

    for (int j = 0; j < logn; j++) {
        for (int i = 0; i < n; i++) {
            p[j + 1][i] = p[j][p[j][i]];
        }
    }

    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            std::swap(x, y);
        }
        while (dep[x] > dep[y]) {
            x = p[std::__lg(dep[x] - dep[y])][x];
        }
        if (x == y) {
            return x;
        }
        for (int i = std::__lg(dep[x]); i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        return p[0][x];
    };
    
    std::vector<int> fl(n), fu(n);
    std::vector<i64> ans(n);
    for (int i = 0; i < q; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        int l = lca(u, v);
        fl[l]++;
        fu[u]++;
        fu[v]++;

        ans[0] += l + 1;
    }

    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[0][x]) {
                continue;
            }
            self(y);
            fu[x] += fu[y];
            fl[x] += fl[y];
        }
    } (0);

    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[0][x]) {
                continue;
            }
            ans[y] = ans[x] + (i64)(fu[y] - 2 * fl[y]) * (y - x);
            self(y);
        }
    } (0);
 
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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