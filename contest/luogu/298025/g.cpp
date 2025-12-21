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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    vector<bool> busy(n);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;

        busy[a[i]] = true;
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
    
    if (k == n) {
        cout << "No\n";
        return 0;
    }
    int st = find(busy.begin(), busy.end(), false) - busy.begin();

    queue<int> q;
    q.push(st);

    vector<bool> vis(n);
    vis[st] = true;

    vector<vector<int>> nadj(n);

    vector<int> ord;
    while (not q.empty()) {
        int x = q.front();
        q.pop();

        ord.push_back(x);

        for (auto y : adj[x]) {
            if (vis[y]) {
                continue;
            }
            nadj[x].push_back(y);
            vis[y] = true;

            if (not busy[y]) {
                q.push(y);
            }
        }
    }

    if (count(vis.begin(), vis.end(), false)) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n" << count_if(nadj.begin(), nadj.end(), [](const auto &v) {
        return not v.empty();
    }) << "\n";

    for (auto x : ord) {
        if (not nadj[x].empty()) {
            cout << x + 1 << " " << nadj[x].size() << " ";
            for (auto y : nadj[x]) {
                cout << y + 1 << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}