#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

template <class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;

    SegmentTree() = delete;
    SegmentTree(int n_, const Info &v_ = {}) { init(std::vector<Info>(n_, v_)); }
    template <class T>
    SegmentTree(const std::vector<T> &data) {
        init(data);
    }

    template <class T>
    void init(const std::vector<T> &data) {
        n = data.size();
        info.assign(4 << std::__lg(n), {});
        auto build = [&](auto &self, int p, int l, int r) -> void {
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
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
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
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
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

constexpr i64 inf = 1e18;

struct Info {
    std::array<int, 2> c {};
    std::array<i64, 2> v {-inf, -inf};
};

Info operator+(const Info &a, const Info &b) {
    Info res;
    if (a.v[0] > b.v[0]) {
        res.v[0] = a.v[0];
        res.c[0] = a.c[0];
    } else {
        res.v[0] = b.v[0];
        res.c[0] = b.c[0];
    }
    for (int i = 0; i < 2; i++) {
        if (a.c[i] != res.c[0] and a.v[i] > res.v[1]) {
            res.c[1] = a.c[i];
            res.v[1] = a.v[i];
        }
    }
    for (int i = 0; i < 2; i++) {
        if (b.c[i] != res.c[0] and b.v[i] > res.v[1]) {
            res.c[1] = b.c[i];
            res.v[1] = b.v[i];
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, C, x0;
    std::cin >> n >> C >> x0;

    std::vector<std::array<i64, 4>> s {{x0, x0 + 1, 0, 0}}; // {[l, r), col, v}
    SegmentTree<Info> seg(2e5);
    for (int step = 0; step < n; step++) {
        int k;
        std::cin >> k;

        std::vector<int> L(k), R(k), A(k), B(k), c(k), w(k);
        for (int i = 0; i < k; i++) {
            std::cin >> L[i] >> R[i] >> A[i] >> B[i] >> c[i] >> w[i];
            R[i]++;
            B[i]++;
        }
        std::vector<int> ord(k);
        rgs::iota(ord, 0);
        rgs::sort(ord, [&](int i, int j) {
            return R[i] < R[j];
        });

        const int m = s.size();
        rgs::sort(s);
        std::vector<std::pair<i64, i64>> vr(m);
        for (int i = 0; i < m; i++) {
            vr[i] = {s[i][1], i};
        }
        rgs::sort(vr);

        std::vector<std::array<i64, 4>> ns {};

        for (int i = 0; i < m; i++) {
            seg.modify(i, Info());
        }

        int j = 0;
        for (int i : ord) {
            while (j < m and s[j][0] < R[i]) {
                int p = std::distance(vr.begin(), rgs::lower_bound(vr, {s[j][1], j}));
                seg.modify(p, Info{{(int)s[j][2], 0}, {s[j][3], -inf}});
                j++;
            }
            int p = std::distance(vr.begin(), rgs::lower_bound(vr, {L[i] + 1, -inf}));
            auto info = seg.rangeQuery(p, m);

            i64 res = -inf;
            if (info.c[0] != c[i] and info.v[0] != -inf) {
                res = info.v[0] + w[i];
            } else if (info.v[1] != -inf) {
                res = info.v[1] + w[i];
            }
            if (res != -inf) {
                ns.push_back({A[i], B[i], c[i], res});
            }
        }

        s = std::move(ns);
    }

    i64 ans = -inf;
    for (auto [_, __, c, v] : s) {
        if (c != 0) {
            ans = std::max(ans, v);
        }
    }
    if (ans == -inf) {
        ans = -1;
    }
    std::cout << ans << "\n";
}