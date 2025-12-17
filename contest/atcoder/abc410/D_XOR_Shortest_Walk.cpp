#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using p32 = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<p32>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w});
    }

    queue<p32> q;
    q.push({0, 0});

    vector<bitset<1024>> f(n);
    f[0][0] = 1;

    while (not q.empty()) {
        auto [d, u] = q.front();
        q.pop();

        for (auto [v, w] : adj[u]) {
            int nd = d ^ w;
            if (not f[v][nd]) {
                f[v][nd] = true;
                q.push({nd, v});
            }
        }
    }
    if (f[n - 1].none()) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < 1024; i++) {
            if (f[n - 1].test(i)) {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}