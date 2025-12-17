#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int query(int u, int v) {
    cout << "? " << u + 1 << " " << v + 1 << endl;

    int ans;
    cin >> ans;

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    auto addEdge = [&](int x, int y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    };
    auto delEdge = [&](int x, int y) {
        adj[x].erase(find(adj[x].begin(), adj[x].end(), y));
        adj[y].erase(find(adj[y].begin(), adj[y].end(), x));
    };

    for (int x = 0; x < n; x++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u != -1) {
            addEdge(x, u);
        }
        if (v != -1) {
            addEdge(x, v);
        }
    }

    int cur = 0;
    for (;;) {

        vector<int> siz(n), f(n);
        [&](this auto &&self, int x, int p) -> void {
            siz[x] = 1;
            for (auto y : adj[x]) {
                if (y == p) {
                    continue;
                }
                self(y, x);

                siz[x] += siz[y];

                f[x] = max(f[x], siz[y]);
            }
        } (cur, -1);

        int tot = siz[cur];
        for (int x = 0; x < n; x++) {
            f[x] = max(f[x], tot - siz[x]);
        }

        cur = min_element(f.begin(), f.end()) - f.begin();

        if (int deg = adj[cur].size(); deg == 0) {
            cout << "! " << cur + 1 << endl;
            return;
        } else if (deg == 1) {
            int x = cur;
            int y = adj[cur][0];

            if (query(x, y) == 0) {
                cout << "! " << x + 1 << endl;
            } else {
                cout << "! " << y + 1 << endl;
            }

            return;
        } else {
            ranges::sort(adj[cur], [&](int i, int j) {
                return siz[i] > siz[j];
            });

            int x = adj[cur][0];
            int y = adj[cur][1];
            if (int ans = query(x, y); ans == 0) {
                delEdge(cur, x);
                cur = x;
            } else if (ans == 2) {
                delEdge(cur, y);
                cur = y;
            } else {
                delEdge(cur, x);
                delEdge(cur, y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

/*
1
8
0 0
1 4
2 0
0 0
7 8
0 0
3 0
6 0
*/