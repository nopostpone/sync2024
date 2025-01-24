#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector adj(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> cnt;

    auto dfs = [&](auto self, int u, int fa, int dep) -> void {
        if (dep > k / 2) {
            return;
        }
        cnt.insert(u);
        for (auto v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u, dep + 1);
        }
    };

    int ans = 0;
    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            cnt.clear();
            dfs(dfs, i, -1, 0);
            ans = max<int>(ans, cnt.size());
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j : adj[i]) {
                if (j < i) {
                    continue;
                }
                cnt.clear();
                dfs(dfs, i, -1, 0);
                dfs(dfs, j, -1, 0);
                ans = max<int>(ans, cnt.size());
            }
        }
    }

    cout << n - ans << "\n";

    return 0;
}