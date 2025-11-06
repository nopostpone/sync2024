#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> f;
    int cur = 0;

    vector<array<int, 3>> a, b;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (not f.contains(u)) {
            f[u] = cur++;
        }
        if (not f.contains(v)) {
            f[v] = cur++;
        }
        if (w == 1) {
            a.push_back({f[u], f[v], w});
        } else {
            b.push_back({f[u], f[v], w});
        }
    }
    DSU dsu(2 * n);
    for (auto [u, v, w] : a) {
        dsu.merge(u, v);
    }

    bool ok = true;
    for (auto [u, v, w] : b) {
        if (dsu.same(u, v)) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}