#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr ll inf = 1e10;

struct Tag {
    bool rev = 0;

    void apply(const Tag &t) {
        rev ^= t.rev;
    }
};

struct Info {
    ll min = inf;
    ll max = -inf;
    ll sum = 0;
    int act = 0;

    void apply(const Tag &t) {
        if (t.rev) {
            min = -min;
            max = -max;
            swap(min, max);
            sum = -sum;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.max = std::max(a.max, b.max);
    c.min = std::min(a.min, b.min);
    c.sum = a.sum + b.sum;
    c.act = a.act + b.act;
    return c;
}

template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() : n(0) {}

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template <class T>
    LazySegmentTree(const std::vector<T> &init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
    }

    template <class T>
    void init(const std::vector<T> &init_) {
        n = init_.size();
        info.assign(4 << (int)std::log2(n), Info());
        tag.assign(4 << (int)std::log2(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r == l) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 1, n);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r == l) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x <= m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info &v) {
        modify(1, 1, n, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 1, n, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l > y || r < x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 1, n, l, r, v);
    }
};

LazySegmentTree<Info, Tag> l;

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

    Info query_path(int u, int v) {
        Info ret;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                ret = ret + l.rangeQuery(in[top[u]], in[u]);
                u = parent[top[u]];
            } else {
                ret = ret + l.rangeQuery(in[top[v]], in[v]);
                v = parent[top[v]];
            }
        }
        if (dep[u] < dep[v])
            std::swap(u, v);
        ret = ret + l.rangeQuery(in[v] + 1, in[u]);
        return ret;
    }

    void update_path(int u, int v) {
        Tag t = {true};
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                l.rangeApply(in[top[u]], in[u], t);
                u = parent[top[u]];
            } else {
                l.rangeApply(in[top[v]], in[v], t);
                v = parent[top[v]];
            }
        }
        if (dep[u] < dep[v])
            std::swap(u, v);
        l.rangeApply(in[v] + 1, in[u], t);
    }

    void modify_node(int u, int k) {
        Info t;
        t.act = 1;
        t.max = t.min = t.sum = k;
        l.modify(in[u], t);
    }
};

struct edge {
    int x, y, z, id;
};

void solve() {
    int n, m;
    cin >> n;

    HLD hld(n);
    vector<edge> e;
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        hld.addEdge(x, y);
        e.push_back({x, y, z, i});
    }
    hld.work(0);

    vector<int> a(n);
    for (auto &&[x, y, z, id] : e) {
        if (hld.parent[y] == x) {
            swap(x, y);
        }
        a[x] = z;
    }

    vector<Info> info(n + 1);
    info[hld.in[1]].act = 1;
    for (int i = 1; i < n; i++) {
        info[hld.in[i]].max = a[i];
        info[hld.in[i]].sum = a[i];
        info[hld.in[i]].min = a[i];
        info[hld.in[i]].act = 1;
    }
    l.init(info);

    cin >> m;
    while (m--) {
        string opt;
        int x, y;
        cin >> opt >> x >> y;
        if (opt == "C") {
            hld.modify_node(e[x - 1].x, y);
        } else if (opt == "N") {
            hld.update_path(x, y);
        } else if (opt == "SUM") {
            cout << hld.query_path(x, y).sum << endl;
        } else if (opt == "MAX") {
            cout << hld.query_path(x, y).max << endl;
        } else if (opt == "MIN") {
            cout << hld.query_path(x, y).min << endl;
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}