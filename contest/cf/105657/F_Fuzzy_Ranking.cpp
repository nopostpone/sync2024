#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

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

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    SCC scc(n);

    vector a(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {
            scc.addEdge(a[i][j - 1], a[i][j]);
        }
    }
    const auto &adj = scc.adj;
    auto bel = scc.work();

    vector<vector<int>> seq(k);
    vector<vector<i64>> f(k);
    for (int i = 0; i < k; i++) {
        seq[i].push_back(0);
        for (int j = 1; j < n; j++) {
            if (bel[a[i][j]] != bel[a[i][j - 1]]) {
                seq[i].push_back(j);
            }
        }
        seq[i].push_back(n);

        f[i].resize(seq[i].size());
        f[i][0] = 0;
        for (int j = 1; j < seq[i].size(); j++) {
            int len = seq[i][j] - seq[i][j - 1];
            f[i][j] = i64(len) * (len - 1) / 2;
            f[i][j] += f[i][j - 1];
        }
    }

    i64 ans = 0;
    for (int _ = 0; _ < q; _++) {
        i64 i, l, r;
        cin >> i >> l >> r;

        i = (i + ans) % k;
        l = (l + ans) % n;
        r = (r + ans) % n;
        r++;

        int pl = lower_bound(seq[i].begin(), seq[i].end(), l) - seq[i].begin();
        int pr = upper_bound(seq[i].begin(), seq[i].end(), r) - seq[i].begin() - 1;

        // cerr << seq[i][pl] << " " << seq[i][pr] << endl;

        if (seq[i][pl] > r) {
            ans = i64(r - l) * (r - l - 1) / 2;
        } else {
            ans = 0;
            ans += i64(seq[i][pl] - l) * (seq[i][pl] - l - 1) / 2;
            ans += i64(seq[i][pr] - r) * (seq[i][pr] - r + 1) / 2;
            ans += f[i][pr] - f[i][pl];
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}