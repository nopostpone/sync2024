#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

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
        if (l >= y || r <= x || !pred(info[p])) {
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
        if (l >= y || r <= x || !pred(info[p])) {
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

constexpr int V = 1e5;

struct Info {
    array<i64, 4> f;
    int cnt;

    Info() : f(), cnt() {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;

    for (int i = 0; i < 4; i++) {
        c.f[i] = a.f[i] + b.f[(i + a.cnt) % 4];
    }

    c.cnt = a.cnt + b.cnt;
    return c;
}

Info get(int x, int c) {
    c %= 4;

    Info a;
    if (x < 0) {
        a.f = {x, -x, -x, x};
    } else {
        a.f = {x, -x, x, -x};
    }
    a.cnt = 1;

    Info res;
    for (int i = 0; i < c; i++) {
        res = res + a;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<int> cnt(2 * V);
    i64 ori = 0;
    SegmentTree<Info> seg(2 * V);
    for (int i = 0; i < n; i++) {
        int d = a[i] - b[i];

        cnt[d + V]++;
        ori += a[i] + b[i];
        seg.modify(d + V, get(d, cnt[d + V]));
    }

    auto answer = [&]() {
        auto ans = ori + seg.rangeQuery(0, 2 * V).f[0];
        ans /= 2;
        cout << ans << "\n";
    };
    answer();

    for (int _ = 0; _ < m; _++) {
        int i, x, y;
        cin >> i >> x >> y;
        i--;

        ori -= a[i] + b[i];
        cnt[a[i] - b[i] + V]--;
        seg.modify(a[i] - b[i] + V, get(a[i] - b[i], cnt[a[i] - b[i] + V]));

        a[i] = x;
        b[i] = y;

        ori += a[i] + b[i];
        cnt[a[i] - b[i] + V]++;
        seg.modify(a[i] - b[i] + V, get(a[i] - b[i], cnt[a[i] - b[i] + V]));

        answer();
    }

    return 0;
}