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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
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

    vector<set<int>> s(n);
    vector<int> w(n);

    int ans = 0;

    [&](this auto &&self, int x, int p) -> void {
        s[x] = {w[x]};

        bool valid = true;

        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            w[y] = w[x] ^ a[y];
            self(y, x);

            if (s[x].size() < s[y].size()) {
                swap(s[x], s[y]);
            }
            for (auto v : s[y]) {
                if (s[x].contains(v ^ a[x])) {
                    valid = false;
                }
            }
            for (auto v : s[y]) {
                s[x].insert(v);
            }
            s[y].clear();
        }
        if (not valid) {
            ans++;
            s[x].clear();
        }
    } (0, -1);

    cout << ans << "\n";

    return 0;
}
