#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

constexpr int inf = 1e9;

struct Tag {
    int val = inf;
    void apply(const Tag &t) {
        val = min(val, t.val);
    }
};

struct Info {
    int bot = inf;
    void apply(const Tag &t) {
        bot = min(bot, t.val);
    }
};

Info operator+(const Info &a, const Info &b) {
    return {min(a.bot, b.bot)};
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int H, W, N;
    cin >> H >> W >> N;
    
    vector<array<int, 4>> a(N);
    for (int i = 0; i < N; i++) {
        for (int j : {0, 1, 2}) {
            cin >> a[i][j];
        }
        a[i][3] = i;
    }

    ranges::sort(a, greater<>());

    LazySegmentTree<Info, Tag> seg(vector(W, Info{H}));

    vector<int> res(N);
    for (auto [y, x, l, id] : a) {
        x--;
        res[id] = seg.rangeQuery(x, x + l).bot;
        seg.rangeApply(x, x + l, {res[id] - 1});
    }
    for (auto i : res) {
        cout << i << "\n";
    }

    return 0;
}