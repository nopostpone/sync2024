#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    unordered_map<i64, int> edges;
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[(i64)u * n + v] = c;
        edges[(i64)v * n + u] = c;
    }

    vector<int> p(n);
    p[0] = -1;
    vector<map<int, i64>> f(n);

    i64 ans = 0;
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            int c = edges[(i64)x * n + y];
            f[x][a[y]] += c;
            p[y] = x;
            if (a[x] != a[y]) {
                ans += c;
            }

            self(y);
        }
    }(0);

    while (q--) {
        int v, x;
        cin >> v >> x;
        v--;

        int fa = p[v];
        if (fa != -1) {
            int e = edges[(i64)v * n + fa];

            f[fa][a[v]] -= e;
            if (a[fa] != a[v]) {
                ans -= e;
            }
            f[fa][x] += e;
            if (a[fa] != x) {
                ans += e;
            }
        }

        if (f[v].contains(a[v])) {
            ans += f[v][a[v]];
        }
        if (f[v].contains(x)) {
            ans -= f[v][x];
        }
        a[v] = x;

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}