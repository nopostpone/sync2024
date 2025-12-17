#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    std::vector<int> f, siz;
    vector<set<int>> kth;

    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        kth.assign(n, {});
        for (int i = 0; i < n; i++) {
            kth[i].insert(i);
        }
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
        for (auto i : kth[y]) {
            kth[x].insert(i);
        }
        if (kth[x].size() > 10) {
            auto it = kth[x].end();
            for (int i = 0; i < 10; i++) {
                it--;
            }
            kth[x].erase(kth[x].begin(), it);
        }
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }

    int getkth(int x, int k) {
        x = find(x);
        k--;
        auto it = kth[x].rbegin();
        while (k--) {
            it++;
        }
        return *it;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1) {
            x--, y--;
            dsu.merge(x, y);

        } else {
            x--;
            if (dsu.size(x) < y) {
                cout << -1 << "\n";
            } else {
                cout << dsu.getkth(x, y) + 1 << "\n";
            }
        }
    }

    return 0;
}