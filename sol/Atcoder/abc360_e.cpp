#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    using pil = pair<int, ll>;
    vector adj(n, vector<pil>());
    
    ll E = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        E += w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dst(n);
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto [v, w] : adj[u]) {
            if (v != fa) {
                dst[v] = dst[u] + w;
                self(self, v, u);
            }
        }
    };
    dfs(dfs, 0, -1);

    int X = max_element(dst.begin(), dst.end()) - dst.begin();
    dst[X] = 0;

    dfs(dfs, X, -1);

    ll A = *max_element(dst.begin(), dst.end());

    cout << 2 * E - A << endl;
    return 0;
}