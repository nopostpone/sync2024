#include <bits/stdc++.h>
#define endl "\n"
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
    
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        dsu.merge(i, j - 1);
    }

    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            dsu.siz[dsu.find(i)]--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dsu.size(i) << " \n"[i == n - 1];
    }

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}