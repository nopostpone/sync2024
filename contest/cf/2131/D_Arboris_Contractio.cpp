#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ori = 0;
    for (int x = 0; x < n; x++) {
        ori += (deg[x] == 1);
    }
    int ans = ori;
    for (int x = 0; x < n; x++) {
        int res = ori;
        if (deg[x] == 1) {
            res--;
        }
        for (int y : adj[x]) {
            res -= (deg[y] == 1);
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
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