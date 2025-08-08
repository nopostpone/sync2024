#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, _;
    cin >> n >> _;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
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
    vector<set<int>> vec(n);
    i64 ans = 0;

    auto color = [&](this auto &&self, int x, int p) -> void {
        c[x] = c[p];
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (c[y] == 0) {
                self(y, x);
            }
        }
    };

    [&](this auto &&self, int x, int p) -> void {
        vector<int> a;
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(y, x);

            if (vec[x].size() < vec[y].size()) {
                swap(vec[x], vec[y]);
            }
            for (auto v : vec[y]) {
                if (vec[x].contains(v)) {
                    a.push_back(v);
                } else {
                    vec[x].insert(v);
                }
            }
        }

        ranges::sort(a);
        a.erase(unique(a.begin(), a.end()), a.end());

        if (a.size() > 1 or (a.size() == 1 and c[x] and a[0] != c[x])) {
            ans += w[x];
        }

        if (c[x]) {
            vec[x].insert(c[x]);
        } else if (not a.empty()) {
            c[x] = a[0];
        } else if (not vec[x].empty()) {
            c[x] = *vec[x].begin();
        }
        if (c[x]) {
            for (auto y : adj[x]) {
                if (y == p) {
                    continue;
                }
                if (c[y] == 0) {
                    color(y, x);
                }
            }
        }
    }(0, -1);

    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << max(c[i], 1) << " \n"[i == n - 1];
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