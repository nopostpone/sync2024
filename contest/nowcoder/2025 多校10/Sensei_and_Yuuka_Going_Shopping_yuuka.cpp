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
} scc;

constexpr int N = 150000;
int leaf[N];

void build(int p, int l, int r) {
    if (r - l == 1) {
        leaf[l] = p;
        return;
    }
    int m = (l + r) / 2;
    build(p * 2, l, m);
    build(p * 2 + 1, m, r);

    scc.addEdge(p, p * 2);
    scc.addEdge(p, p * 2 + 1);
}
void connect(int p, int l, int r, int x, int y, int u) {
    if (r <= x or l >= y) {
        return;
    }
    if (r <= y and l >= x) {
        scc.addEdge(u, p);
        return;
    }
    int m = (l + r) / 2;

    connect(p * 2, l, m, x, y, u);
    connect(p * 2 + 1, m, r, x, y, u);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto v = a;
    ranges::sort(v);
    for (auto &x : a) {
        x = lower_bound(v.begin(), v.end(), x) - v.begin();
    }

    vector<int> l(n, -1), r(n, n);
    for (int i = 0; i < n; i++) {
        r[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        l[a[i]] = i;
    }

    scc.init(4 * n);
    build(1, 0, n);
    int ecnt = 0;
    for (int i = 0; i < n; i++) {
        if (l[a[i]] == -1 or l[a[i]] == i or r[a[i]] == n or r[a[i]] == i) {
            continue;
        }
        ecnt++;
        connect(1, 0, n, l[a[i]] + 1, r[a[i]], leaf[i]);
    }

    if (ecnt == 0) {
        cout << 0 << "\n"
             << 1 << " " << 2 << "\n";
        return;
    }
    auto bel = scc.work();

    vector<set<int>> f(4 * n);
    for (int i = 0; i < n; i++) {
        if (l[a[i]] == -1 or l[a[i]] == i or r[a[i]] == n or r[a[i]] == i) {
            continue;
        }
        int x = leaf[i];

        f[bel[x]].insert(a[i]);
    }
    int u = -1, maxsiz = 0;
    for (int i = 0; i < n; i++) {
        int x = leaf[i];
        if (f[bel[x]].size() > maxsiz) {
            maxsiz = f[bel[x]].size();
            u = bel[x];
        }
    }

    int L = 0, R = n;
    
    for (int i = 0; i < n; i++) {
        if (l[a[i]] == -1 or l[a[i]] == i or r[a[i]] == n or r[a[i]] == i) {
            continue;
        }
        int x = leaf[i];
        if (f[u].contains(a[i])) {
            L = max(L, l[a[i]] + 1);
            R = min(R, r[a[i]]);
        }
    }

    cout << maxsiz << "\n";
    cout << L + 1 << " " << R + 1 << "\n";
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