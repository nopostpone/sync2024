#include <bits/stdc++.h>
using namespace std;

template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() = delete;
    LazySegmentTree(int n_, const Info &v_ = {}) { init(std::vector<Info>(n_, v_)); }
    LazySegmentTree(const std::vector<Info> &data) { init(data); }

    void init(const std::vector<Info> &data) {
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
        if (l >= y || r <= x || !pred(info[p])) {
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
        if (l >= y || r <= x || !pred(info[p])) {
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
    int add;
    void apply(const Tag &t) {
        add += t.add;
    }
};

struct Info {
    int idx = -1;
    int cnt = 0;

    void apply(const Tag &t) {
        cnt += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    if (a.cnt == b.cnt) {
        return (a.idx < b.idx ? a : b);
    }
    return (a.cnt < b.cnt ? b : a);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    map<int, int> f;
    for (int i = 0; i < n; i++) {
        f[i] = a[i];
    }

    vector<Info> init(2 * n);
    for (int v = 0; v < 2 * n; v++) {
        init[v].idx = v;
        init[v].cnt = 0;
    }
    LazySegmentTree<Info, Tag> seg(init);
    for (auto x : a) {
        seg.rangeApply(x, x + 1, {1});
    }

    auto split = [&](int i) {
        auto it = f.upper_bound(i);
        assert(it != f.begin());
        it--;
        if (it->first == i) {
            return;
        }
        auto [j, d] = *it;
        f[i] = i - j + d;
    };

    auto ans = [&]() {
        auto [idx, cnt] = seg.rangeQuery(0, 2 * n);
        cout << idx + 1 << " " << cnt << "\n";
    };
    ans();

    while (m--) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        d--;

        split(l);
        split(r);
        for (auto it = f.find(l); it->first != r; it = f.erase(it)) {
            auto [x, d] = *it;
            int y = next(it)->first;

            seg.rangeApply(d, d + y - x, {-1});
        }
        f[l] = d;
        seg.rangeApply(d, d + r - l, {1});

        ans();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}

/*
3
3 3
1 2 3
1 1 2
2 2 3
3 3 1
1 1
1
1 1 1
8 8
7 6 6 4 3 8 5 3
4 4 4
6 8 6
1 1 7
4 7 4
6 7 6
2 7 5
1 5 7
1 6 8

1 1
2 2
3 2
1 1
1 1
1 1
3 2
3 2
6 3
6 3
6 3
6 3
7 2
8 2
8 2
*/
