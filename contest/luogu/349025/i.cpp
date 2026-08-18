#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

namespace rgs = std::ranges;

template <class T>
struct DSU {
    std::vector<int> f, siz;
    std::vector<T> w;

    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        w.assign(n, T());
    }
    int find(int x) {
        if (x != f[x]) {
            int y = find(f[x]);
            w[x] ^= w[f[x]];
            f[x] = y;
        }
        return f[x];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y, T k) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return (w[x] ^ w[y]) == k;
        }
        // union by rank
        if (siz[rx] < siz[ry]) {
            f[rx] = ry;
            w[rx] = k ^ w[x] ^ w[y];
            siz[ry] += siz[rx];
        } else {
            f[ry] = rx;
            w[ry] = k ^ w[x] ^ w[y];
            siz[rx] += siz[ry];
        }
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, c;
    std::cin >> n >> c;

    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
    }

    DSU<u64> dsu(n);

    int ans = c;
    for (int i = 0; i < c; i++) {
        int u, v;
        u64 w;
        std::cin >> u >> v >> w;
        u--;
        v--;

        if (not dsu.merge(u, v, w)) {
            ans = std::min(ans, i);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}