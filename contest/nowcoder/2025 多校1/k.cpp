#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < c[i]; j++) {
            int v;
            cin >> v;
            v--;
            adj[i].push_back(v);
        }
    }

    vector f(n, vector<int>(3, -1));
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int x, int cur) -> int {
        // if (f[x][cur] != -1) {
        //     return f[x][cur];
        // }
        // if (c[x] == 1) {
        //     return 1;
        // }
        // int y = adj[x][(cur + 1) % c[x]];
        // int nxt = find(adj[y].begin(), adj[y].end(), x) - adj[y].begin();

        // f[x][cur] = self(self, y, nxt) + 1;
        // return f[x][cur];
        vis[x] = true;
        vis[x] = false;
    };

    for (int x = 0; x < n; x++) {
        cout << dfs(dfs, x, c[x] - 1) << "\n";
    }

    return 0;
}

/*
6
3 4 2 3
3 5 1 3
3 6 1 2
1 1
1 2
1 3

*/