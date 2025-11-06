#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct DSU {
    std::vector<int> siz, f;
    std::vector<std::pair<int *, int>> his;

    DSU () {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        his.emplace_back(&siz[x], siz[x]);
        siz[x] += siz[y];
        his.emplace_back(&f[y], f[y]);
        f[y] = x;
        return true;
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x];
        }
        return x;
    }
    int size(int x) {
        return siz[find(x)];
    }
    void undo(int x) {
        while (int(his.size()) > x) {
            *his.back().first = his.back().second;
            his.pop_back();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    map<array<int, 2>, int> edges[2];

    vector<vector<array<int, 3>>> f(4 * q);

    auto addEdge = [&](this auto &&self, int p, int l, int r, int x, int y, int t, int u, int v) {
        if (l >= y or r <= x) {
            return;
        }
        if (l >= x and r <= y) {
            f[p].push_back({t, u, v});
            return;
        }
        int m = (l + r) / 2;
        self(2 * p, l, m, x, y, t, u, v);
        self(2 * p + 1, m, r, x, y, t, u, v);
    };

    for (int i = 0; i < q; i++) {
        char g;
        int x, y;
        cin >> g >> x >> y;
        x--;
        y--;

        if (x > y) {
            swap(x, y);
        }
        int t = g - 'A';
        if (edges[t].contains({x, y})) {
            addEdge(1, 0, q, edges[t][{x, y}], i, t, x, y);
            edges[t].erase({x, y});
        } else {
            edges[t][{x, y}] = i;
        }
    }
    for (int t = 0; t < 2; t++) {
        for (auto [e, i] : edges[t]) {
            auto [x, y] = e;
            addEdge(1, 0, q, i, q, t, x, y);
        }
    }

    // dsu[0] : A 和 B 的并
    // dsu[1] : A
    DSU dsu[2] {n, n};
    // 我们维护并集的连通块个数，和 A 的连通块个数，答案就是后者减去前者。
    auto work = [&](this auto &&self, int p, int l, int r, int S, int A) -> void {
        int tm[2] = {dsu[0].his.size(), dsu[1].his.size()};

        for (auto [t, u, v] : f[p]) {
            S -= dsu[0].merge(u, v);
            if (t == 0) {
                A -= dsu[1].merge(u, v);
            }
        }
        if (r - l == 1) {
            cout << A - S << "\n";
        } else {
            int m = (l + r) / 2;
            self(2 * p, l, m, S, A);
            self(2 * p + 1, m, r, S, A);
        }
        for (int t = 0; t < 2; t++) {
            dsu[t].undo(tm[t]);
        }
    };
    work(1, 0, q, n, n);

    return 0;
}