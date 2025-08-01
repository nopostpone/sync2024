#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector dis(n + 1, vector<i64>(n + 1, inf));
    for (int i = 0; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dis[u][v] = min<i64>(dis[u][v], w);
        dis[v][u] = min<i64>(dis[v][u], w);
    }
    int k, t;
    cin >> k >> t;
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        d--;
        dis[d][n] = t;
        dis[n][d] = 0;
    }

    for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int o;
        cin >> o;

        if (o == 1) {
            int x, y, t;
            cin >> x >> y >> t;
            x--;
            y--;
            dis[x][y] = min<i64>(dis[x][y], t);
            dis[y][x] = min<i64>(dis[y][x], t);
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    dis[i][j] = min({dis[i][j],
                                     dis[i][x] + dis[x][y] + dis[y][j],
                                     dis[i][y] + dis[y][x] + dis[x][j]});
                }
            }
        } else if (o == 2) {
            int x;
            cin >> x;
            x--;
            dis[x][n] = t;
            dis[n][x] = 0;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    dis[i][j] = min({dis[i][j],
                                     dis[i][x] + t + dis[n][j],
                                     dis[i][n] + dis[x][j]});
                }
            }
        } else {
            i64 ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dis[i][j] == inf) {
                        continue;
                    }
                    ans += dis[i][j];
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}