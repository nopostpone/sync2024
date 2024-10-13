// HLD + LazySegmentTree 维护路在HLD中加入getPath和getTree，和数据结构解耦。径/子树信息
// 24.10.13 upd: 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int P;

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
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
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
        return dep[u] < dep[v] ? u : v;
    }
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    bool isAncester(int fa, int son) {
        return in[fa] <= in[son] && in[son] < out[fa];
    }
    auto getPath(int u, int v) {
        vector<pair<int, int>> ret;
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                ret.push_back({in[top[u]], in[u]});
                u = parent[top[u]];
            } else {
                ret.push_back({in[top[v]], in[v]});
                v = parent[top[v]];
            }
        }
        if (dep[u] > dep[v]) {
            ret.push_back({in[v], in[u]});
        } else {
            ret.push_back({in[u], in[v]});
        }
        return ret;
    }
    pair<int, int> getTree(int u) {
        return make_pair(in[u], out[u]);
    }
};

template<class Info, class Tag>
struct LazySegmentTree {
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
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
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};
struct Tag {
    int add = 0;
    void apply(const Tag &t) {
        add = (add + t.add) % P;
    }
};
struct Info {
    int sum = 0;
    int act = 0;
    void apply(const Tag &t) {
        sum = (1ull * t.add * act + sum) % P;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.sum = (a.sum + b.sum) % P;
    c.act = a.act + b.act;
    return c;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m, rt;
    cin >> n >> m >> rt >> P;
    rt--;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    HLD hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
    }
    hld.work(rt);

    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[hld.in[i]].sum = a[i];
        init[hld.in[i]].act = 1;
    }
    LazySegmentTree<Info, Tag> seg(init);

    while (m--) {
        int op;
        cin >> op;
        if (op <= 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            auto b = hld.getPath(x, y);
            if (op == 1) {
                int z;
                cin >> z;
                for (auto [u, v] : b) {
                    seg.rangeApply(u, v + 1, {z % P});
                }
            } else {
                int ans = 0;
                for (auto [u, v] : b) {
                    ans = (ans + seg.rangeQuery(u, v + 1).sum) % P;
                }
                cout << ans << "\n";
            }
        } else {
            int x;
            cin >> x;
            x--;
            auto [u, v] = hld.getTree(x);
            if (op == 3) {
                int z;
                cin >> z;
                seg.rangeApply(u, v, {z % P});
            } else {
                cout << (seg.rangeQuery(u, v).sum % P) << "\n";
            }
        }
    }
    
    return 0;
}