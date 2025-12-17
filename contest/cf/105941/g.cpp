#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

// int getD(const vector<vector<int>> &adj) {
//     int n = adj.size();

//     vector<int> dep(n);
//     auto dfs = [&](auto &&self, int x, int p) -> void {
//         for (auto y : adj[x]) {
//             if (y == p) {
//                 continue;
//             }
//             dep[y] = dep[x] + 1;
//             self(self, y, x);
//         }
//     };
//     dfs(dfs, 0, -1);

//     int u = max_element(dep.begin(), dep.end()) - dep.begin();
//     dep[u] = 0;
//     dfs(dfs, u, -1);

//     return ranges::max(dep);
// }

// int getM(const vector<vector<int>> &adj) {
//     int n = adj.size();
//     vector<array<int, 2>> dp(n);
//     auto dfs = [&](auto &&self, int x, int p) -> void {
//         dp[x][1] = 1;
//         for (auto y : adj[x]) {
//             if (y == p) {
//                 continue;
//             }
//             self(self, y, x);
//             dp[x][0] += max(dp[y][1], dp[y][0]);
//             dp[x][1] += dp[y][0];
//         }
//     };
//     dfs(dfs, 0, -1);

//     return ranges::max(dp[0]);
// }

void solve(int n) {
    if (n == 4) {
        cout << -1 << "\n";
        return;
    }
    if (n == 6) {
        for (int i = 1; i <= 4; i++) {
            cout << i << " " << i + 1 << "\n";
        }
        cout << 4 << " " << 6 << "\n";
        return;
    }

    vector<pair<int, int>> edges;
    int m = (n + 1) / 2;
    int cnt = m;

    int cur = 1;

    for (int i = 0; i < m / 2; i++) {
        edges.emplace_back(cur - 1, cur);
        if (i % 2 == 0) {
            cnt--;
        }
        cur++;
    }
    int remain = cur;
    for (int i = 0; i < (m + 1) / 2; i++) {
        edges.emplace_back((i == 0 ? 0 : cur - 1), cur);
        if (i % 2 == 0) {
            cnt--;
        }
        cur++;
    }

    while (cnt) {
        if (n - cur > cnt and m / 2 > 1) {
            edges.emplace_back(0, cur);
            edges.emplace_back(cur, cur + 1);
            cur += 2;
        } else {
            edges.emplace_back(0, cur);
            cur++;
        }

        cnt--;
    }
    
    if (cur < n) {
        edges.emplace_back(remain, n - 1);
    }

    vector<vector<int>> adj(n);
    for (auto [x, y] : edges) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // if (getD(adj) != m or getM(adj) != m) {
    //     cout << -1 << "\n";
    //     return;
    // }
    
    for (auto [x, y] : edges) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}

/*
3
5
3
4

*/
