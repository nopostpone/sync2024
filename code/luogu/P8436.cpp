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

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].emplace_back(v, i * 2);
        adj[v].emplace_back(u, i * 2 + 1);
    }

    vector<int> dfn(n, -1), low(n), stk, bel(n, -1);
    int cur = 0, cnt = 0;
    auto dfs = [&](this auto &&self, int x, int p) -> void {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto [y, i] : adj[x]) {
            if (i == (p ^ 1)) {
                continue;
            }

            if (dfn[y] == -1) {
                self(y, i);
                low[x] = min(low[x], low[y]);
            } else {
                low[x] = min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;

                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    };

    for (int i = 0; i < n; i++) {
        if (dfn[i] == -1) {
            dfs(i, -1);
        }
    }

    vector<vector<int>> vec(cnt);
    for (int i = 0; i < n; i++) {
        vec[bel[i]].push_back(i);
    }
    cout << cnt << "\n";

    for (int i = 0; i < cnt; i++) {
        cout << vec[i].size() << " ";
        for (auto x : vec[i]) {
            cout << x + 1 << " \n"[x == vec[i].back()];
        }
    }

    return 0;
}
