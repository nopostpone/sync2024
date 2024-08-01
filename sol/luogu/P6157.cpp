// https://www.luogu.com.cn/problem/P6157
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e10;

multiset<int> s;

struct Tag {
    ll add = 0;

    void apply(const Tag &t) {
        add += t.add;
    }
};

struct Info {
    ll max = -inf;
    ll sec = -inf;
    ll act = 0;

    void apply(const Tag &t) {
        max += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    priority_queue<ll, vector<ll>> tmp;
    tmp.push(a.max);
    tmp.push(a.sec);
    tmp.push(b.max);
    tmp.push(b.sec);
    c.act = a.act + b.act;
    c.max = tmp.top();
    while (tmp.top() == c.max and !tmp.empty())
        tmp.pop();
    if (!tmp.empty()) {
        c.sec = tmp.top();
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

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void modify(int p, int l, int r, int x, const Tag &v) {
        if (r == l) {
            info[p].apply(v);
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
        ret = ret + l.rangeQuery(in[v], in[u]);
        return ret;
    }
};

#define endl "\n"

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
        s.insert(a[i]);
    }

    vector<Info> info(n + 1);
    for (int i = 1; i <= n; i++) {
        info[hld.in[i]].max = a[i];
        info[hld.in[i]].sec = -inf;
        info[hld.in[i]].act = 1;
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
                cout << -1 << endl;
                continue;
            }
            cout << t.sec << " ";
            s.erase(s.find(t.max));
            s.erase(s.find(t.sec));
            cout << (*(--s.lower_bound(*--s.end()))) << endl;
            s.insert(t.max);
            s.insert(t.sec);
        } else {
            s.erase(s.find(a[x]));
            s.insert(a[x] + y);
            l.modify(hld.in[x], {y});
        }
    }

    return 0;
}