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

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> siz(n);
    [&](this auto &&self, int x, int p) -> void {
        if (p != -1) {
            adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
        }
        siz[x] = 1;
        for (auto &y : adj[x]) {
            self(y, x);
            siz[x] += siz[y];
            if (siz[y] > siz[adj[x][0]]) {
                swap(adj[x][0], y);
            }
        }
    } (0, -1);

    vector<int> cnt(n + 1);
    vector<i64> sum(n + 1), ans(n);

    int cur = 0;

    auto addv = [&](int x, int t) {
        sum[cnt[x]] -= x;

        cnt[x] += t;
        cur = max(cur, cnt[x]);

        sum[cnt[x]] += x;
        while (cur > 0 and sum[cur] == 0) {
            cur--;
        }
    };

    auto add = [&](this auto &&self, int x, int t) -> void {
        addv(c[x], t);
        for (auto y : adj[x]) {
            self(y, t);
        }
    };
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y != adj[x][0]) {
                self(y);
                add(y, -1);
            }
        }
        if (not adj[x].empty()) {
            self(adj[x][0]);
            for (auto y : adj[x]) {
                if (y != adj[x][0]) {
                    add(y, 1);
                }
            }
        }
        addv(c[x], 1);
        ans[x] = sum[cur];
    } (0);
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}