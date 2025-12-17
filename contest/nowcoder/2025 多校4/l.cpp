#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> f;

    DSU(int n) : n(n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        f[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<pair<int, int>>> add(n), del(n);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        int l = upper_bound(a.begin(), a.end(), x) - a.begin();
        int r = n - y;
        if (l > r) {
            continue;
        }
        add[l].emplace_back(x, i);
        del[r].emplace_back(x, i);
    }
    DSU dsu(q);
    map<int, int> f;
    vector<int> ans(q), val(q);

    for (int l = 0; l < n; l++) {
        for (auto [x, i] : add[l]) {
            if (f.contains(x)) {
                dsu.merge(f[x], i);
            } else {
                f[x] = i;
                val[i] = x;
            }
        }
        map<int, int> nf;
        for (auto [x, i] : f) {
            int y = (x + a[l] + 1) / 2;
            if (nf.contains(y)) {
                dsu.merge(nf[y], i);
            } else {
                nf[y] = i;
                val[i] = y;
            }
        }
        f = move(nf);

        for (auto [x, i] : del[l]) {
            ans[i] = val[dsu.find(i)] - x;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }


    return 0;
}

