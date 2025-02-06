#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int logn = __lg(n);
    vector g(logn + 1, vector<int>(n));
    vector p(logn + 1, vector<int>(n, -1));

    vector<int> dep(n), h(n);

    auto dfs = [&](auto self, int u) -> void {
        array<int, 2> f{};
        for (auto v : adj[u]) {
            if (v == p[0][u]) {
                continue;
            }
            dep[v] = dep[u] + 1;
            p[0][v] = u;
            self(self, v);

            int x = h[v] + 1;
            if (x > f[0]) {
                f = {x, f[0]};
            } else if (x > f[1]) {
                f[1] = x;
            }
        }
        h[u] = f[0];
        for (auto v : adj[u]) {
            if (v != p[0][u]) {
                g[0][v] = f[f[0] == 1 + h[v]] + 1;
            }
        }
    };
    dfs(dfs, 0);

    for (int i = 0; i < logn; i++) {
        for (int x = 0; x < n; x++) {
            if ((2 << i) <= dep[x]) {
                p[i + 1][x] = p[i][p[i][x]];
                g[i + 1][x] = max(g[i][x], g[i][p[i][x]] + (1 << i));
            }
        }
    }

    int q;
    for (cin >> q; q--;) {
        int u, k;
        cin >> u >> k;
        u--;
        k = min(k, dep[u]);

        int ans = h[u];
        int len = 0;

        for (int i = logn; i >= 0; i--) {
            if ((k >> i) & 1) {
                ans = max(ans, g[i][u] + len);
                u = p[i][u];
                len += (1 << i);
            }
        }
        cout << ans << " \n"[q == 0];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}