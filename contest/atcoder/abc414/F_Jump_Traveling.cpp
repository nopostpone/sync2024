#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector f(n, vector<i64>(k, inf));

    deque<pair<int, int>> q;
    q.emplace_back(0, 0);
    f[0][0] = 0;

    while (not q.empty()) {
        auto [x, r] = q.front();
        q.pop_front();

        int nr = (r + 1) % k;
        int w = (r + 1 == k);

        for (int y : adj[x]) {
            if (f[x][r] + w < f[y][nr]) {
                f[y][nr] = f[x][r] + w;

                if (w) {
                    q.emplace_back(y, nr);
                } else {
                    q.emplace_front(y, nr);
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        auto ans = f[i][0];
        if (ans >= inf) {
            ans = -1;
        }
        cout << ans << " \n"[i == n - 1];
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}

