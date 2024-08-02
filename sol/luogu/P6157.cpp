// https://www.luogu.com.cn/problem/P6157

// 当你 RE 的时候
// 自己造点简单数据测试一下

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1;

multiset<int> s;

struct Tag {
    int add = 0;

    void apply(const Tag &t) {
        add += t.add;
    }
};

struct Info {
    int max = -inf;
    int sec = -inf;

    // apply 调用时必定为单个点的区间
    void apply(const Tag &t) {
        max += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.max = max<int>(a.max, b.max);
    if (a.max == c.max) {
        c.sec = a.sec;
    } else {
        c.sec = a.max;
    }
    if (b.max == c.max) {
        c.sec = max(c.sec, b.sec);
    } else {
        c.sec = max(c.sec, b.max);
    }
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
        n = init_.size() - 1;
        info.assign(n << 2, Info());
        tag.assign(n << 2, Tag());
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

    void modify(int p, int l, int r, int x, const Tag &v) {
        if (r == l) {
            s.erase(s.find(info[p].max));
            info[p].apply(v);
            s.insert(info[p].max);
            return;
        }
        int m = (l + r) / 2;
        if (x <= m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Tag &v) {
        modify(1, 1, n, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        Info ret;
        if (x <= m)
            ret = ret + rangeQuery(p * 2, l, m, x, y);
        if (m < y)
            ret = ret + rangeQuery(p * 2 + 1, m + 1, r, x, y);
        return ret;
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 1, n, l, r);
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
        return ret + l.rangeQuery(in[v], in[u]);
    }
};

#define endl "\n"
vector<pair<int, bool>> res;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    HLD hld(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        hld.addEdge(u, v);
    }
    hld.work(1);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        s.insert(a[i]);
    }

    vector<Info> info(n + 1);
    for (int i = 1; i <= n; i++) {
        info[hld.in[i]].max = a[i];
        info[hld.in[i]].sec = -inf;
    }
    l.init(info);

    int m;
    cin >> m;
    while (m--) {
        bool opt;
        int x, y;
        cin >> opt >> x >> y;
        if (opt) {
            Info t = hld.query_path(x, y);
            if (t.sec == -inf) {
                res.push_back({-1, true});
                continue;
            }
            res.push_back({t.sec, false});
            s.erase(s.find(t.max));
            s.erase(s.find(t.sec));
            res.push_back({*(--s.lower_bound(*s.rbegin())), true});
            s.insert(t.max);
            s.insert(t.sec);
        } else {
            l.modify(hld.in[x], {y});
        }
    }

    for (auto &&[u, v] : res) {
        cout << u << " \n"[v];
    }
    return 0;
}