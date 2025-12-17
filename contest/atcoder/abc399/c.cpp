#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
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

    int ans = 0;

    vector<bool> vis(n);
    auto work = [&](int st) {
        queue<int> q;
        q.push(st);
        while (not q.empty()) {
            int x = q.front();
            q.pop();
            for (auto y : adj[x]) {
                if (vis[y]) {
                    continue;
                }
                ans++;
                q.push(y);
                vis[y] = true;
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (not vis[i]) {
            vis[i] = true;
            work(i);
        }
    }

    cout << m - ans << "\n";

    return 0;
}