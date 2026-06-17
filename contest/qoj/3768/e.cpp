#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

namespace rgs = std::ranges;

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
    template <class F>
    int findFirst(int p, int l, int r, int x, int y, const F &pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        push(p);
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findFirst(int l, int r, const F &pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F>
    int findLast(int p, int l, int r, int x, int y, const F &pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        push(p);
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template <class F>
    int findLast(int l, int r, const F &pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Tag {
    int add = 0;
    void apply(const Tag &t) {
        add += t.add;
    }
};

constexpr i64 inf = 2147483648;

struct Info {
    i64 x1 = inf;
    i64 x2 = inf;
    void apply(const Tag &t) {
        x1 += t.add;
        x2 += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {std::min(a.x1, b.x1), std::min(a.x2, b.x2)};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<int> in(n), out(n), parent(n);
    std::vector<int> dep(n);
    int cur = 0;
    parent[0] = -1;
    [&](this auto &&self, int x) -> void {
        in[x] = cur++;
        for (auto y : adj[x]) {
            if (y == parent[x]) {
                continue;
            }
            parent[y] = x;
            dep[y] = dep[x] + 1;
            self(y);
        }
        out[x] = cur;
    } (0);

    LazySegmentTree<Info, Tag> seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(in[i], {inf, dep[i]});
    }

    int z = 0;

    for (int _ = 0; _ < m; _++) {
        int op, x;
        std::cin >> op >> x;
        x--;

        if (op == 1) {
            auto info = seg.rangeQuery(in[x], in[x] + 1);

            if (info.x1 == info.x2) {
                info.x1 = inf;
            } else {
                info.x1 = info.x2;
            }
            seg.modify(in[x], info);
        } else {
            if (x == parent[z]) {
                seg.rangeApply(in[z], out[z], {1});
                seg.rangeApply(0, in[z], {-1});
                seg.rangeApply(out[z], n, {-1});
            } else {
                seg.rangeApply(in[x], out[x], {-1});
                seg.rangeApply(0, in[x], {1});
                seg.rangeApply(out[x], n, {1});
            }

            z = x;
        }

        auto ans = seg.rangeQuery(0, n).x1;
        if (ans > n) {
            ans = inf;
        }
        std::cout << ans << "\n";
    }
}