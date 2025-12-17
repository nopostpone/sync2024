#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

struct DSU {
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

constexpr int inf = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    vector<array<int, 3>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (w and i > j) {
                edges.push_back({w, i, j});
            }
        }
    }
    ranges::sort(edges);

    int ans = inf;

    for (int s = 0; s < (1 << n); s++) {
        DSU dsu(n);
        int cnt = 0;
        int cost = 0;
        for (auto &[w, i, j] : edges) {
            if ((s >> i & 1) and (s >> j & 1)) {
                continue;
            }
            if (dsu.merge(i, j)) {
                cnt++;
                cost += w;
            }
        }
        if (cnt == n - 1) {
            ans = min(ans, cost + c * (n - __builtin_popcount(s)));
        }
    }
    cout << ans << "\n";

    return 0;
}