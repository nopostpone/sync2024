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

    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        adj[a[i]].push_back(i);
        adj[b[i]].push_back(i);
    }

    queue<int> q;
    vector<bool> vis(n + 1);

    q.push(0);
    while (not q.empty()) {
        int x = q.front();
        q.pop();

        for (auto y : adj[x]) {
            if (not vis[y]) {
                vis[y] = true;
                q.push(y);
            }
        }
    }

    cout << count(vis.begin() + 1, vis.end(), true) << "\n";

    return 0;
}