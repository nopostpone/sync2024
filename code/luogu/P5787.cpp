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
    int same(int x, int y) {
        return find(x) == find(y);
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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<array<int, 2>>> f(4 * k);

    auto addEdge = [&](auto &&self, int p, int l, int r, int x, int y, int u, int v) -> void {
        if (l >= y or r <= x) {
            return;
        }
        if (l >= x and r <= y) {
            f[p].push_back({u, v});
            return;
        }
        int m = (l + r) / 2;
        self(self, 2 * p, l, m, x, y, u, v);
        self(self, 2 * p + 1, m, r, x, y, u, v);
    };

    for (int i = 0; i < m; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        x--;
        y--;
        addEdge(addEdge, 1, 0, k, l, r, x, y);
    }

    DSU dsu(2 * n);
    auto work = [&](auto &&self, int p, int l, int r, bool ok) -> void {
        auto ori = (int)dsu.his.size();

        for (auto [u, v] : f[p]) {
            if (not ok) {
                break;
            }
            dsu.merge(u, v + n);
            dsu.merge(v, u + n);
            if (dsu.same(u, u + n) or dsu.same(v, v + n)) {
                ok = false;
            }
        }
        if (r - l == 1) {
            cout << (ok ? "Yes" : "No") << "\n";
        } else {
            int m = (l + r) / 2;
            self(self, 2 * p, l, m, ok);
            self(self, 2 * p + 1, m, r, ok);
        }

        dsu.undo(ori);
    };
    work(work, 1, 0, k, true);

    return 0;
}