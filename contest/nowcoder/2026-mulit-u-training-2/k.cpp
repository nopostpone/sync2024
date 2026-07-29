#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

constexpr i64 inf = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, T;
    std::cin >> n >> m >> T;

    std::vector<std::pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        edges[i] = {u, v};
    }

    int k;
    std::cin >> k;
    std::vector<int> id(k);
    std::vector<i64> w(k);

    std::vector<bool> fl(m);
    
    std::vector<int> seq, key(n, -1);
    for (int i = 0; i < k; i++) {
        std::cin >> id[i] >> w[i];
        id[i]--;
        fl[id[i]] = true;

        auto [u, v] = edges[id[i]];
        if (key[u] == -1) {
            key[u] = seq.size();
            seq.push_back(u);
        }
        if (key[v] == -1) {
            key[v] = seq.size();
            seq.push_back(v);
        }
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        if (!fl[i]) {
            auto [u, v] = edges[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    for (int i = 0; i < n; i++) {
        rgs::sort(adj[i]);
        adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    std::vector d0(n, std::vector<i64>(n, inf));
    for (int i = 0; i < n; i++) {
        d0[i][i] = 0;
        std::queue<int> q;
        q.push(i);

        while (not q.empty()) {
            int x = q.front();
            q.pop();

            for (auto y : adj[x]) {
                if (d0[i][y] == inf) {
                    d0[i][y] = d0[i][x] + T;
                    q.push(y);
                }
            }
        }
    }

    int q;
    std::cin >> q;

    const int numk = seq.size();

    std::vector adj2(numk, std::vector<i64>(numk, inf));
    for (int _ = 0; _ < q; ++_) {
        int x;
        i64 y;
        std::cin >> x >> y;
        x--;

        for (int i = 0; i < k; i++) {
            if (id[i] == x) {
                w[i] = y;
                break;
            }
        }

        for (int i = 0; i < numk; i++) {
            for (int j = 0; j < numk; j++) {
                adj2[i][j] = d0[seq[i]][seq[j]];
            }
        }

        for (int i = 0; i < k; i++) {
            auto [u, v] = edges[id[i]];

            int ui = key[u];
            int vi = key[v];

            if (ui != -1 and vi != -1) {
                adj2[ui][vi] = std::min(adj2[ui][vi], w[i]);
                adj2[vi][ui] = std::min(adj2[vi][ui], w[i]);
            }
        }

        int L;
        std::cin >> L;
        for (int _ = 0; _ < L; _++) {
            int a, b;
            std::cin >> a >> b;
            a--;
            b--;

            std::vector<i64> d(numk);
            for (int i = 0; i < numk; i++) {
                d[i] = d0[a][seq[i]];
            }

            std::vector<bool> vis(numk);
            for (int __ = 0; __ < numk; __++) {
                int u = -1;
                i64 tem = inf;
                for (int i = 0; i < numk; i++) {
                    if (not vis[i] and d[i] < tem) {
                        tem = d[i];
                        u = i;
                    }
                }

                if (u == -1) {
                    break;
                }
                vis[u] = true;

                for (int v = 0; v < numk; v++) {
                    if (not vis[v] and d[u] + adj2[u][v] < d[v]) {
                        d[v] = d[u] + adj2[u][v];
                    }
                }
            }

            i64 ans = d0[a][b];
            
            for (int i = 0; i < numk; i++) {
                if (d[i] != inf and d0[seq[i]][b] != inf) {
                    ans = std::min(ans, d[i] + d0[seq[i]][b]);
                }
            }

            std::cout << ans << "\n";
        }




    }
}