#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template<class Info, class Tag>
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
        };
        build(build, 1, 0, n);
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
    Info Query(int p, int l, int r, int i) {
        if (r - l == 1) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        if (m > i) {
            return Query(2 * p, l, m, i);
        } else {
            return Query(2 * p + 1, m, r, i);
        }
    }
    Info Query(int i) {
        return Query(1, 0, n, i);
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
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};

struct Tag {
    int typ = 0;
    void apply(const Tag &v) {
        if (v.typ == 2) {
            if (typ == 0) {
                typ = 2;
            } else if (typ == -1) {
                typ = 1;
            } else if (typ == 1) {
                typ = -1;
            } else {
                typ = 0;
            }
        } else if (v.typ != 0) {
            typ = v.typ;
        }
    }
};
struct Info {
    int val = 1;
    void apply(const Tag &v) {
        if (v.typ == 2) {
            val = -val;
        } else if (v.typ != 0) {
            val = v.typ;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int k = 100010;
    LazySegmentTree<Info, Tag> seg(2 * k + 1);

    for (int i = 0; i < m; i++) {
        char c;
        int x;
        cin >> c >> x;

        if (x >= 0) {
            if (c == '<') {
                // [x, k + 1) -> 1
                seg.rangeApply(x + k, 2 * k + 1, {1});
                // [-x + 1, x) -> rev
                seg.rangeApply(k - x + 1, k + x, {2});
                // [-k, -x + 1) -> -1
                seg.rangeApply(0, k - x + 1, {-1});
            } else {
                // [x + 1, k + 1) -> -1
                seg.rangeApply(k + x + 1, 2 * k + 1, {-1});
                // [-k, -x) -> 1
                seg.rangeApply(0, k - x, {1});
            }
        } else {
            if (c == '<') {
                // [-k, x) -> -1
                seg.rangeApply(0, x + k, {-1});
                // [-x + 1, k + 1) -> 1
                seg.rangeApply(k - x + 1, 2 * k + 1, {1});
            } else {
                // [-k, x + 1) -> 1
                seg.rangeApply(0, x + k + 1, {1});
                // [x + 1, -x) -> rev
                seg.rangeApply(x + 1 + k, k - x, {2});
                // [-x, k + 1) -> -1
                seg.rangeApply(k - x, 2 * k + 1, {-1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << seg.Query(a[i] + k).val * a[i] << " \n"[i == n - 1];
    }

    return 0;
}