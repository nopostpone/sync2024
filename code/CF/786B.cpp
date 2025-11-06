// 线段树优化建图 板子

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 1e5, D = 4e5;
constexpr i64 inf = 1e18;

using pii = pair<i64, i64>;

vector<pii> adj[N * 8];
int leaf[N];

void addEdge(int u, int v, i64 w) {
    adj[u].push_back({v, w});
}

void build(int p, int l, int r) {
    if (l == r - 1) {
        leaf[l] = p;
        return;
    }
    int m = (l + r) / 2;
    build(p * 2, l, m);
    build(p * 2 + 1, m, r);

    addEdge(p, p * 2, 0);
    addEdge(p, p * 2 + 1, 0);

    addEdge(p * 2 + D, p + D, 0);
    addEdge(p * 2 + 1 + D, p + D, 0);
}

int mod;
void connect(int p, int l, int r, int x, int y, int v, i64 w) {
    if (r <= x or l >= y) {
        return;
    }
    if (x <= l and r <= y) {
        if (mod) {
            addEdge(p + D, v, w);
        } else {
            addEdge(v, p, w);
        }
        return;
    }
    int m = (l + r) / 2;
    connect(p * 2, l, m, x, y, v, w);
    connect(p * 2 + 1, m, r, x, y, v, w);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, s;
    cin >> n >> q >> s;
    s--;

    build(1, 0, n);

    for (int i = 0; i < q; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            addEdge(leaf[u], leaf[v], w);

        } else {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            v--, l--;
            mod = o % 2;
            connect(1, 0, n, l, r, leaf[v], w);
        }
    }

    for (int i = 0; i < n; i++) {
        addEdge(leaf[i], leaf[i] + D, 0);
        addEdge(leaf[i] + D, leaf[i], 0);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<i64> ans(8 * N, inf);

    pq.push({0, leaf[s]});
    ans[leaf[s]] = 0;

    while (not pq.empty()) {
        auto [cur, u] = pq.top();
        pq.pop();

        if (ans[u] < cur) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (cur + w < ans[v]) {
                ans[v] = cur + w;
                pq.push({cur + w, v});
            }
        }
    }

    for (int i = 0, j; i < n; i++) {
        j = leaf[i];
        cerr << i << " " << j << endl;
        if (ans[j] == inf) {
            ans[j] = -1;
        }
        cout << ans[j] << " \n"[i == n - 1];
    }

    return 0;
}