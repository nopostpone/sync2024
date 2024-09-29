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
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> q(m);
    for (auto &&[a, d, k] : q) {
        cin >> a >> d >> k;
    }

    DSU dsu(n);
    int ans = n;

    for (int x = 1; x <= 10; x++) {
        vector<int> f(n);
        for (auto [a, d, k] : q) {
            if (d == x) {
                f[a]++;
                f[a + k * d]--;
            }
        }
        for (int i = x; i < n; i++) {
            f[i] += f[i - x];
        }
        for (int i = 0; i < n; i++) {
            if (f[i]) {
                ans -= dsu.merge(i, i + x);
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}