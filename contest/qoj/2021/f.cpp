#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int C = 50;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < C; i++) {
        vector<array<int, 2>> f(n);
        vector<pair<int, int>> q;
        for (int x = 0; x < n; x++) {
            if (c[x] == i) {
                f[x] = {-1, x};
                q.emplace_back(x, x);
            } else {
                f[x] = {x, x};
            }
        }
        for (int _ = 0; _ < k - 1; _++) {
            vector<pair<int, int>> nq;
            for (auto [x, s] : q) {
                for (auto y : adj[x]) {
                    if (y != s) {
                        if (f[y][0] == y) {
                            f[y][0] = s;
                            nq.emplace_back(y, s);
                        } else if (f[y][1] == y and f[y][0] != s) {
                            f[y][1] = s;
                            nq.emplace_back(y, s);
                        }
                    }
                }
            }
            q = move(nq);
        }

        for (int x = 0; x < n; x++) {
            if (c[x] == i and f[x][1] != x) {
                cout << "NO\n";
                return;
            }
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