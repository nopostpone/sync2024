#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct HLD {
    int n;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> adj;
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
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }

        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                swap(v, adj[u][0]);
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
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
                      return in[x] < in[y];
                  }) -
                  1;
        return *it;
    }
};

template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = {}) { init(n_, v_); }
    LazySegmentTree(vector<Info> a) { init(a); }

    void init(int n_, Info v_) {
        init(vector<Info>(n_, v_));
    }
    void init(vector<Info> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), {});
        tag.assign(4 << __lg(n), {});

        auto build = [&](auto self, int p, int l, int r) -> void {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m, r);
            pull(p);
        };
        build(build, 1, 0, n);
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

constexpr i64 inf = 1e18;

struct Tag {
    i64 cov = inf;
    void apply(const Tag &t) {
        if (t.cov != inf) {
            cov = t.cov;
        }
    }
};
struct Info {
    i64 min;
    Info() : min(inf) {}
    Info(i64 x) : min(x) {}
    void apply(const Tag &t) {
        if (t.cov != inf) {
            min = t.cov;
        }
    }
};
constexpr Info operator+(const Info &a, const Info &b) {
    return {min(a.min, b.min)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    HLD hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int rt;
    cin >> rt;
    rt--;
    hld.work(rt);

    LazySegmentTree<Info, Tag> seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(hld.in[i], Info(a[i]));
    }

    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            cin >> rt;
            rt--;
        } else if (o == 2) {
            int x, y, cov;
            cin >> x >> y >> cov;
            x--, y--;
            auto path = hld.getPath(x, y);
            for (auto [u, v] : path) {
                seg.rangeApply(u, v + 1, {cov});
            }
        } else {
            int x;
            cin >> x;
            x--;
            i64 ans;
            if (x == rt) {
                ans = seg.rangeQuery(0, n).min;
            } else {
                if (hld.isAncester(x, rt)) {
                    auto fa = hld.rootedParent(rt, x);
                    auto [u, v] = hld.getTree(fa);
                    ans = min(seg.rangeQuery(0, u).min,
                              seg.rangeQuery(v, n).min);
                } else {
                    auto [u, v] = hld.getTree(x);
                    ans = seg.rangeQuery(u, v).min;
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}