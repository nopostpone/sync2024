#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /**
     * dp0 : no constrain
     * dp1 : must have a path contains root as a endpoint
    */
    vector<array<i64, 6>> dp0(n), dp1(n);
    vector<int> siz(n);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        siz[x] = 1;

        /**
         * g0 : can't choose x
         * g1 : choose x as endpoint
         * g2 : choose x not as endpoint (a -> x -> b)
        */
        i64 g[3][6]{};
        g[1][1] = a[x];

        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }

            self(self, y, x);
            i64 ng[3][6]{};
            for (int i = 0; i <= min(k, siz[x]); i++) {
                for (int j = 0; j <= min({k, k - i, siz[y]}); j++) {
                    ng[0][i + j] = max(ng[0][i + j], g[0][i] + dp0[y][j]);
                    if (i) {
                        ng[1][i + j] = max(ng[1][i + j], g[1][i] + dp0[y][j]);
                        ng[2][i + j] = max(ng[2][i + j], g[2][i] + dp0[y][j]);
                    }
                    if (j) {
                        /**
                         * have chosen i paths (without x)
                         * + j paths in subtree y (with y)
                         * extend one path endpoint y -> x
                        */
                        ng[1][i + j] = max(ng[1][i + j], g[0][i] + dp1[y][j] + a[x]);
                    }
                }
            }
            for (int i = 1; i <= min(k, siz[x]); i++) {
                for (int j = 1; j <= min({k, k - i + 1, siz[y]}); j++) {
                    /**
                     * have chosen i paths (with x)
                     * + j paths (with y)
                     * connect y <-> x, reduce numbers of paths by 1
                    */
                    ng[2][i + j - 1] = max(ng[2][i + j - 1], g[1][i] + dp1[y][j]);
                }
            }
            swap(g, ng);
            siz[x] += siz[y];
        }
        for (int i = 0; i <= min(k, siz[x]); i++) {
            dp0[x][i] = max(dp0[x][i], g[0][i]);
            if (i) {
                dp1[x][i] = max(dp1[x][i], g[1][i]);
                dp0[x][i] = max({dp0[x][i], g[1][i], g[2][i]});
            }
        }
    };
    dfs(dfs, 0, -1);

    cout << ranges::max(dp0[0]) << "\n";

    return 0;
}