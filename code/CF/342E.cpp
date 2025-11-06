#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dep(n);
    vector<array<int, 20>> p(n);

    [&](this auto &&self, int x) -> void {
        for (int i = 1; i <= __lg(n); i++) {
            p[x][i] = p[p[x][i - 1]][i - 1];
        }
        for (auto y : adj[x]) {
            if (y == p[x][0]) {
                continue;
            }
            dep[y] = dep[x] + 1;
            p[y][0] = x;
            self(y);
        }
    } (0);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        while (dep[u] > dep[v]) {
            u = p[u][__lg(dep[u] - dep[v])];
        }
        if (u == v) {
            return u;
        }

        for (int i = __lg(dep[u]); i >= 0; i--) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i];
                v = p[v][i];
            }
        }
        return p[u][0];
    };
    auto dis = [&](int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    };

    const int B = sqrt(n / __lg(n));
    int cur = 0;

    vector<int> red{0};
    vector<int> ori(n, n);
    for (int i = 0; i < q; i++) {
        int o, x;
        cin >> o >> x;
        x--;

        if (o == 1) {
            red.push_back(x);
        } else {
            int ans = ori[x];
            for (auto y : red) {
                ans = min(ans, dis(x, y));
            }
            cout << ans << "\n";
        }

        if (i > B * cur) {
            queue<int> q;
            for (auto x : red) {
                q.push(x);
                ori[x] = 0;
            }

            while (not q.empty()) {
                int x = q.front();
                q.pop();

                for (auto y : adj[x]) {
                    if (ori[x] + 1 >= ori[y]) {
                        continue;
                    }
                    ori[y] = ori[x] + 1;
                    q.push(y);
                }
            }

            red.clear();
            cur++;

        }
    }

    return 0;
}