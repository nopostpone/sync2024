#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) {
            swap(u, v);
        }
        if (u < v) {
            adj[u].push_back(v);
        }
    }
    for (int x = 0; x < n; x++) {
        ranges::sort(adj[x]);
    }
    
    int p = 0, ans = 0;
    [&](this auto &&self, int x) -> void {
        p++;
        for (int i = 0; i < adj[x].size(); i++) {
            if (i and adj[x][i] == adj[x][i - 1]) {
                continue;
            }
            int y = adj[x][i];
            while (y > p) {
                ans++;
                self(p);
            }
            if (y == p) {
                self(y);
            }
        }
        while (x == 0 and p != n) {
            ans++;
            self(p);
        }
    } (0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
