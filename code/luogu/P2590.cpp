#include <bits/stdc++.h>
#define lst pos << 1
#define rst pos << 1 | 1
#define endl "\n"
using namespace std;
using ll = long long;
using i64 = long long;

const ll inf = 1e18;

struct Node {
    int l, r, mx;
    ll sum;
};

vector<Node> s;

void pullup(int pos) {
    s[pos].sum = s[lst].sum + s[rst].sum;
    s[pos].mx = max(s[lst].mx, s[rst].mx);
}

void build(int l, int r, int pos, std::vector<int> &a) {
    s[pos].l = l, s[pos].r = r;
    if (l == r) {
        s[pos].sum = s[pos].mx = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, lst, a);
    build(mid + 1, r, rst, a);
    pullup(pos);
}

void init(int n, std::vector<int> init_) {
    s.resize(n << 2);
    build(1, n, 1, init_);
}

void modify(int u, int k, int pos = 1) {
    if (s[pos].l == s[pos].r) {
        s[pos].sum = s[pos].mx = k;
        return;
    }
    int mid = s[pos].l + s[pos].r >> 1;
    if (u <= mid)
        modify(u, k, lst);
    else
        modify(u, k, rst);
    pullup(pos);
}

ll query_sum(int x, int y, int pos = 1) {
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
        return s[pos].sum;
    int mid = s[pos].l + s[pos].r >> 1;
    ll ans = 0;
    if (x <= mid)
        ans += query_sum(x, y, lst);
    if (mid < y)
        ans += query_sum(x, y, rst);
    return ans;
}

int query_mx(int x, int y, int pos = 1) {
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y) {
        return s[pos].mx;
    }
    int mid = s[pos].l + s[pos].r >> 1;
    int mx = -1e9;
    if (x <= mid)
        mx = max(mx, query_mx(x, y, lst));
    if (mid < y)
        mx = max(mx, query_mx(x, y, rst));
    return mx;
}

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;

    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }

        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = ++cur;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }

    void update_u(int u, int t) {
        modify(in[u], t);
    }

    int query_path_mx(int u, int v) {
        int ret = -1e9;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                ret = max(ret, query_mx(in[u], in[top[u]]));
                u = parent[top[u]];
            } else {
                ret = max(ret, query_mx(in[v], in[top[v]]));
                v = parent[top[v]];
            }
        }
        ret = max(ret, query_mx(in[u], in[v]));
        return ret;
    }

    ll query_path_sum(int u, int v) {
        ll ans = 0;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                ans += query_sum(in[u], in[top[u]]);
                u = parent[top[u]];
            } else {
                ans += query_sum(in[v], in[top[v]]);
                v = parent[top[v]];
            }
        }
        ans += query_sum(in[u], in[v]);
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n;
    HLD hld(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        hld.addEdge(x, y);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    hld.work(1);

    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        b[hld.in[i]] = a[i];
    }
    init(n, b);

    cin >> m;
    while (m--) {
        string opt;
        int u, v;
        cin >> opt >> u >> v;
        if (opt == "QMAX") {
            cout << hld.query_path_mx(u, v) << "\n";
        } else if (opt == "QSUM") {
            cout << hld.query_path_sum(u, v) << "\n";
        } else if (opt == "CHANGE") {
            hld.update_u(u, v);
        } else {
            return;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}