#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
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
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SCC scc(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        scc.addEdge(u, v);
    }

    auto bel = scc.work();
    
    const int siz = *max_element(bel.begin(), bel.end()) + 1;
    
    vector<int> b(siz);
    for (int i = 0; i < n; i++) {
        int now = bel[i];
        b[now] += a[i];
    }
    vector<unordered_set<int>> adj(siz);
    for (int i = 0; i < n; i++) {
        for (int j : scc.adj[i]) {
            if (bel[j] == bel[i]) {
                continue;
            }
            adj[bel[i]].insert(bel[j]);
        }
    }

    vector<int> dp(siz, -1);
    auto dfs = [&](auto &&self, int u) -> void {
        for (int v : adj[u]) {
            if (dp[v] != -1) {
                dp[u] = b[u] + dp[v];
                return;
            }
            self(self, u);
            dp[u] = max(dp[u], b[u] + dp[v]);
        }
        dp[u] = b[u];
    };

    for (int i = 0; i < siz; i++) {
        if (dp[i] == -1) {
            dfs(dfs, i);
        }
    }

    int ans = -1;
    for (auto i : dp) {
        ans = max(ans, i);
    }
    cout << ans << endl;

    return 0;
}