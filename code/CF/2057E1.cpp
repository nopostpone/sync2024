#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;
void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 3>> edges(m);
    for (auto &[u, v, w] : edges) {
        cin >> u >> v >> w;
        u--, v--;
    }

    ranges::sort(edges, [](auto i, auto j) {
        return i[2] < j[2];
    });

    vector dis(m + 1, vector(n, vector<int>(n, inf)));
    for (int i = 0; i < n; i++) {
        dis[0][i][i] = 0;
    }

    for (auto [u, v, w] : edges) {
        dis[0][u][v] = dis[0][v][u] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[0][i][j] = min(dis[0][i][j], dis[0][i][k] + dis[0][k][j]);
            }
        }
    }

    int p = 1;
    for (auto [u, v, w] : edges) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[p][i][j] = min({dis[p - 1][i][j],
                                    dis[p - 1][i][v] + dis[p - 1][u][j],
                                    dis[p - 1][i][u] + dis[p - 1][v][j]});
            }
        }
        p++;
    }
    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        int lo = 0, hi = m;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (dis[m][u][v] < k) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        cout << edges[lo - 1][2] << " \n"[q == 0];
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