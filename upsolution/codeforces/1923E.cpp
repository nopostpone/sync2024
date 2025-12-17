#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }

    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<map<int, int>> mp(n);
    i64 ans{};

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);

            if (mp[v].contains(c[u])) { // 起点是 u，终点在 v 的分支里
                ans += mp[v][c[u]];
                mp[v].erase(c[u]);
            }

            if (mp[v].size() > mp[u].size()) { // 优化一下常数
                swap(mp[u], mp[v]);
            }
            for (auto [x, y] : mp[v]) {
                ans += 1ll * y * mp[u][x]; // 起点和终点在同一子树的不同分支
                mp[u][x] += y;
            }
            mp[v].clear();
        }
        mp[u][c[u]]++;
    };
    dfs(dfs, 0, -1);

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}