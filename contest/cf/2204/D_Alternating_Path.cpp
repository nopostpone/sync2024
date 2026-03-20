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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;

    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
        if (vis[i] != -1) {
            continue;
        }

        int cnt[2] {};
        bool bip = true;

        queue<int> q;
        q.push(i);
        vis[i] = 0;

        while (not q.empty()) {
            int x = q.front();
            q.pop();
            cnt[vis[x]]++;

            for (auto y : adj[x]) {
                if (vis[y] == -1) {
                    vis[y] = 1 - vis[x];
                    q.push(y);
                }
                if (vis[y] == vis[x]) {
                    bip = false;
                }
            }
        }
        if (bip) {
            ans += max(cnt[0], cnt[1]);
        }
    }

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