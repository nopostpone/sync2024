#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

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

constexpr int E = 12;

void solve() {
    int n, q;
    cin >> n >> q;

    vector dsu(1 << E, DSU(n));

    auto dfs = [&](this auto &&self, int u, int v, int w) -> void {
        if (dsu[w].same(u, v)) {
            return;
        }
        dsu[w].merge(u, v);

        for (int d = 0; d < E; d++) {
            if (w >> d & 1) {
                self(u, v, w ^ (1 << d));
            }
        }
    };

    i64 ans = 0;
    for (int _ = 0; _ < q; _++) {
        char o;
        int u, v;
        cin >> o >> u >> v;
        u--;
        v--;

        if (o == '+') {
            int w;
            cin >> w;

            dfs(u, v, w);

        } else {
            if (not dsu[0].same(u, v)) {
                ans--;
                continue;
            }

            int res = 0;
            for (int d = E - 1; d >= 0; d--) {
                int w = res + (1 << d);
                if (dsu[w].same(u, v)) {
                    res = w;
                }
            }
            ans += res;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
/*
2
4 11
+ 1 3 6
+ 3 4 2
? 1 4
+ 1 4 3
? 4 1
+ 4 3 4
? 1 4
+ 3 2 3
? 1 2
+ 1 1 4
? 1 3
4 4
+ 1 2 64
+ 3 4 32
? 1 2
? 3 1
*/