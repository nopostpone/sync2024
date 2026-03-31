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

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        ranges::sort(adj[i], [&](auto u, auto v) {
            return b[u.first] < b[v.first];
        });
    }
    
    const int base = n * 3;
    vector<int> dp(n), ans(m, 1);

    if (a[0] != 0) {
        cout << "impossible\n";
        return 0;
    }

    vector<bool> vis(n);
    [&](this auto &&self, int x) -> void {
        vis[x] = true;

        for (auto [y, i] : adj[x]) {
            if (vis[y]) {
                continue;
            }

            if (b[y] != b[x] + dp[x] + 1) {
                cout << "impossible\n";
                std::exit(0);
            }
            ans[i] = base - dp[x]++;
            self(y);
            dp[x] += dp[y];
        }
    } (0);

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}