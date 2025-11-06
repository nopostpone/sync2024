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

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfn(n, -1), low(n);
    basic_string cut(n, false);
    int cur = 0;

    auto work = [&](int r) {

        int son = 0;
        [&](this auto &&self, int x) -> void {
            dfn[x] = low[x] = cur++;
            for (auto y : adj[x]) {
                if (dfn[y] == -1) {
                    if (x == r) {
                        son++;
                    }
                    self(y);
                    low[x] = min(low[x], low[y]);
                    if (low[y] >= dfn[x] and x != r) {
                        cut[x] = true;
                    }
                } else {
                    low[x] = min(low[x], dfn[y]);
                }
            }
        } (r);

        if (son >= 2) {
            cut[r] = true;
        }
    };

    for (int x = 0; x < n; x++) {
        if (dfn[x] == -1) {
            work(x);
        }
    }

    cout << ranges::count(cut, true) << "\n";
    for (int i = 0; i < n; i++) {
        if (cut[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";

    return 0;
}
