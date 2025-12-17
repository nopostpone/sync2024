#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dis(n, inf);
    queue<int> q;

    dis[0] = 0;
    q.push(0);

    while (not q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto y : adj[x]) {
            if (dis[y] == inf) {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }

    vector<int> ans(k);
    for (int i = 0; i < n; i++) {
        ans[a[i]] = max(ans[a[i]], dis[i]);
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " \n"[i == k - 1];
    }
}