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
    
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    vector<int> cnt(n, 1), C(n);
    iota(C.begin(), C.end(), 0);

    while (q--) {
        int o;
        cin >> o;

        if (o == 1) {
            int x, c;
            cin >> x >> c;
            x--, c--;

            x = dsu.find(x);
            cnt[C[x]] -= dsu.size(x);
            cnt[C[x] = c] += dsu.size(x);

            if (x > 0 and C[dsu.find(x - 1)] == c) {
                dsu.merge(x - 1, x);
                x = dsu.find(x);
            }
            if (x + dsu.size(x) < n and C[x + dsu.size(x)] == c) {
                dsu.merge(x, x + dsu.size(x));
            }
        } else {
            int c;
            cin >> c;
            c--;

            cout << cnt[c] << "\n";
        }
    }
    
    return 0;
}