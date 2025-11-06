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
    int n, m, k;
    cin >> n >> m >> k;

    vector<array<int, 3>> edge(m);
    for (auto &&[u, v, w] : edge) {
        cin >> u >> v >> w;
        u--, v--;
    }

    ranges::sort(edge, [&](auto x, auto y) {
        return x[2] < y[2];
    });

    DSU dsu(n);
    int cnt = 0, mx = -1;
    ll ans = 0;
    
    for (auto [u, v, w] : edge) {
        if (cnt == n - 1) {
            break;
        }
        if (dsu.merge(u, v)) {
            mx = w;
            cnt++;
            if (w > k) {
                ans += (w - k);
            }
        }
    }    
    if (mx < k) {
        ans = 2e9;
        for (auto &&[u, v, w] : edge) {
            ans = min<ll>(ans, std::abs(w - k));
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