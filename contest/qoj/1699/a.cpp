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

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_set<u64> e, v;

    {
        queue<int> q;
        q.push(0);

        vector<bool> vis(n);
        vis[0] = true;
        while (not q.empty()) {
            int x = q.front();
            q.pop();

            v.insert(x);
            for (auto y : adj[x]) {
                if (y < x) {
                    continue;
                }
                e.insert(1ll * x * n + y);
                if (not vis[y]) {
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
    }

    if (not v.contains(n - 1)) {
        cout << 0 << "\n";
        return 0;
    }

    int ans = 0;
    {
        queue<int> q;
        q.push(n - 1);

        vector<bool> vis(n);
        vis[n - 1] = true;
        while (not q.empty()) {
            int x = q.front();
            q.pop();

            ans -= v.contains(x);
            for (auto y : adj[x]) {
                if (x < y) {
                    continue;
                }
                ans += e.contains(1ll * y * n + x);
                if (not vis[y]) {
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
    }

    ans += 2;
    cout << ans << "\n";

    return 0;
}