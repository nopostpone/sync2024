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
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dep(n), p(n);
    auto work = [&](int s) -> int {
        queue<int> q;
        q.push(s);
        p[s] = -1;
        dep[s] = 0;

        while (not q.empty()) {
            int x = q.front();
            q.pop();
            
            for (auto y : adj[x]) {
                if (y == p[x]) {
                    continue;
                }
                p[y] = x;
                dep[y] = dep[x] + 1;
                q.push(y);
            }
        }
        return max_element(dep.begin(), dep.end()) - dep.begin();
    };
    auto x = work(0);
    auto y = work(x);

    vector<bool> flag(n);
    for (int i = y; i != -1; i = p[i]) {
        flag[i] = true;
    }
    for (int i = 0; i < n; i++) {
        if (flag[i] or flag[p[i]]) {

        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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