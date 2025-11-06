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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1);
    int ans = n;

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        for (int i = dsu.find(l); i <= r; i = dsu.find(i)) {
            dsu.merge(i + 1, i);
            ans--;
        }
        cout << ans << "\n";
    }
    
    return 0;
}