#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

struct Line {
    double k = 0;
    ll b = inf;
};

template <class Line>
struct LiChaoTree {
#define lst p << 1
#define rst p << 1 | 1
    const double eps = 1e-9;
    int n;
    int cnt;
    vector<int> s;
    vector<Line> l;
    
    LiChaoTree() {}

    LiChaoTree(int n_, int m_) {
        this->init(n_, m_);
    }

    void init(int n_, int m_) {
        this->n = n_;
        this->cnt = 0;
        s.resize(n << 2, 0);
        l.resize(m_ + 1, {});
    }

    template <class T>
    inline double f(int id, T now) {
        return 1. * l[id].k * now + l[id].b;
    }

    template <class T>
    inline int cmp(const T &x, const T &y) {
        if (x - y > eps)
            return 1;
        if (y - x > eps)
            return -1;
        return 0;
    }

    template<class T>
    void addLine(T x0, T y0, T x1, T y1) {
        if (x0 > x1)
            swap(x0, x1), swap(y0, y1);
        cnt++;
        double k, b;
        if (x0 == x1) {
            k = 0;
            b = max(y0, y1);
        } else {
            k = 1. * (y1 - y0) / (1. * (x1 - x0));
            b = 1. * y0 - 1. * x0 * k;
        }
        l[cnt] = {k, b};
    }

    void insert(int p, int l, int r, int u) {
        int &v = s[p];
        int m = l + r >> 1;
        if (cmp(f(u, m), f(v, m)) == 1 or (cmp(f(u, m), f(v, m)) == 0 and u < v)) {
            swap(u, v);
        }
        if (cmp(f(u, l), f(v, l)) == 1 or (cmp(f(u, l), f(v, l)) == 0 and u < v)) {
            insert(lst, l, m, u);
        } else if (cmp(f(u, r), f(v, r)) == 1 or (cmp(f(u, r), f(v, r)) == 0 and u < v)) {
            insert(rst, m + 1, r, u);
        }
        return;
    }

    void upd(int p, int l, int r, int x, int y, int u) {
        if (x <= l and r <= y) {
            insert(p, l, r, u);
            return;
        }
        int m = l + r >> 1;
        if (x <= m)
            upd(lst, l, m, x, y, u);
        if (m < y)
            upd(rst, m + 1, r, x, y, u);
        return;
    }

    void upd(int x, int y) {
        upd(1, 1, n, x, y, cnt);
    }

    pair<double, int> pmax(const pair<double, int> &A, const pair<double, int> &B) {
        int tmp = cmp(A.first, B.first);
        if (tmp == 1)
            return A;
        else if (tmp == -1)
            return B;
        else
            return A.second < B.second ? A : B;
    }

    pair<double, int> pmin(const pair<double, int> &A, const pair<double, int> &B) {
        int tmp = cmp(A.first, B.first);
        if (tmp == 1)
            return B;
        else if (tmp == -1)
            return A;
        else
            return A.second < B.second ? A : B;
    }

    pair<double, int> query(int p, int l, int r, int now) {
        if (r < now or now < l)
            return {0, 0};
        int m = l + r >> 1;
        double res = f(s[p], now);
        if (l == r)
            return {res, s[p]};
        return pmin({res, s[p]}, pmin(query(lst, l, m, now), query(rst, m + 1, r, now)));
    }
};

LiChaoTree<Line> lct;

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
        cur = 1;
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
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = (v == adj[u][0] ? top[u] : v);
            dfs2(v);
        }
        out[u] = cur;
    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return (dep[u] < dep[v]) ? u : v;
    }

    double query_path(int u, int v) {
        pair<double, int> pr;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                pr = lct.pmin(pr, lct.query(in[top[u]], in[u]));
                u = parent[top[u]];
            } else {
                pr = lct.pmin(pr, lct.query(in[top[v]], in[v]));
                v = parent[top[v]];
            }
        }
        if (dep[u] < dep[v])
            std::swap(u, v);
        return lct.pmin(pr, lct.query(in[u], in[v]));
    }

    void update_path(int u, int v, int id) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                lct.addLine(l);
                u = parent[top[u]];
            } else {
                l.rangeApply(in[top[v]], in[v] + 1, t);
                v = parent[top[v]];
            }
        }
        if (dep[u] < dep[v])
            std::swap(u, v);
        l.rangeApply(in[v], in[u] + 1, t);
    }
};

void solve() {

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}