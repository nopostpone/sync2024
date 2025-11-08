#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

template <class T>
constexpr T inf = numeric_limits<T>::max();

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> ori(n);
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v, l, a;
        cin >> u >> v >> l >> a;
        u--;
        v--;
        e[i] = {a, u, v};
        ori[u].emplace_back(v, l);
        ori[v].emplace_back(u, l);
    }

    vector<int> dis(2 * n - 1, inf<int>);
    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);
    
    while (not pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();

        if (d > dis[x]) {
            continue;
        }

        for (auto [y, l] : ori[x]) {
            if (d + l < dis[y]) {
                dis[y] = d + l;
                pq.emplace(dis[y], y);
            }
        }
    }

    ranges::sort(e, greater());

    DSU dsu(2 * n - 1);
    int tot = n;
    vector<vector<int>> adj(2 * n - 1);
    vector<int> lim(2 * n - 1);

    for (auto [a, u, v] : e) {
        u = dsu.find(u);
        v = dsu.find(v);
        if (u == v) {
            lim[u] = max(lim[u], a);
            continue;
        }
        dsu.merge(tot, u);
        dsu.merge(tot, v);
        adj[tot] = {u, v};
        lim[tot] = a;
        tot++;
    }

    vector<array<int, 18>> p(tot);
    p[tot - 1][0] = tot - 1;
    [&](this auto &&self, int x) -> void {
        for (int i = 0; i < 17; i++) {
            p[x][i + 1] = p[p[x][i]][i];
        }
        for (auto y : adj[x]) {
            p[y][0] = x;
            self(y);
            dis[x] = min(dis[x], dis[y]);
        }
    } (tot - 1);

    int q, coef, s;
    cin >> q >> coef >> s;

    int ans = 0;

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        v--;
        v = (v + coef * ans) % n;
        k = (k + coef * ans) % (s + 1);

        for (int i = 17; i >= 0; i--) {
            if (lim[p[v][i]] > k) {
                v = p[v][i];
            }
        }
        ans = dis[v];

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