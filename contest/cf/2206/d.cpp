#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() = delete;
    LazySegmentTree(int n_, const Info &v_ = {}) { init(std::vector<Info>(n_, v_)); }
    template <class T>
    LazySegmentTree(const std::vector<T> &data) { init(data); }

    template <class T>
    void init(const std::vector<T> &data) {
        n = data.size();
        info.assign(4 << std::__lg(n), {});
        tag.assign(4 << std::__lg(n), {});

        auto build = [&](auto self, int p, int l, int r) -> void {
            if (r - l == 1) {
                info[p] = data[l];
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
        tag[p] = {};
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
            return {};
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
    i64 add = 0;
    void apply(const Tag &v) {
        add += v.add;
    }
};

struct Info {
    i64 res = 0;

    Info() {}
    Info(i64 x) : res(x) {}

    void apply(const Tag &v) {
        res += v.add;
    }
};
Info operator+(const Info &a, const Info &b) {
    return {max(a.res, b.res)};
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> siz(n), top(n), parent(n), in(n), seq(n), bot(n);
    vector<vector<int>> adj(n);
    parent[0] = -1;
    
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        parent[i] = p;
        adj[p].push_back(i);
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto dfs1 = [&](auto &&self, int x) -> void {
        siz[x] = 1;

        for (auto &y : adj[x]) {
            self(self, y);
            siz[x] += siz[y];
            if (siz[y] > siz[adj[x][0]]) {
                std::swap(y, adj[x][0]);
            }
        }
        bot[x] = adj[x].empty() ? x : bot[adj[x][0]];
    };
    dfs1(dfs1, 0);
    
    vector<i64> f(n), s(n);

    int cur = 0;
    auto dfs2 = [&](auto &&self, int x) -> void {
        in[x] = cur++;
        seq[in[x]] = x;
        i64 sum = 0;
        
        for (auto y : adj[x]) {
            top[y] = y == adj[x][0] ? top[x] : y;
            self(self, y);
            if (y != adj[x][0]) {
                s[x] += f[y];
            }
            sum += f[y];
        }
        f[x] = max(sum, (i64)a[x]);
    };
    dfs2(dfs2, 0);

    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[in[i]] = a[i];
    }
    LazySegmentTree<Info, Tag> seg(init);
    for (int i = 0; i < n; i++) {
        seg.rangeApply(in[i] + 1, in[bot[i]] + 1, {s[i]});
    }
    
    cout << f[0] << "\n";

    for (int _ = 0; _ < q; _++) {
        int u, x;
        cin >> u >> x;
        u--;

        int l = in[top[u]];
        int r = in[bot[u]] + 1;

        i64 ds = -f[seq[l]];
        seg.rangeApply(in[u], in[u] + 1, {x - a[u]});
        ds += f[seq[l]] = seg.rangeQuery(l, r).res;
        
        for (int v = parent[seq[l]]; v != -1; v = parent[seq[l]]) {
            l = in[top[v]];
            r = in[bot[v]] + 1;
            i64 nds = -f[seq[l]];
            seg.rangeApply(in[v] + 1, r, {ds});
            nds += f[seq[l]] = seg.rangeQuery(l, r).res;
            ds = nds;
        }

        cout << f[0] << "\n";
        a[u] = x;
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
}