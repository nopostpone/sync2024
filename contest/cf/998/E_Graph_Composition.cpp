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
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<array<int, 2>> F(m1), G(m2);
    for (auto &[x, y] : F) {
        cin >> x >> y;
        x--, y--;
    }
    for (auto &[x, y] : G) {
        cin >> x >> y;
        x--, y--;
    }

    DSU g(n);
    for (auto [x, y] : G) {
        g.merge(x, y);
    }

    int ans{};

    DSU f(n);
    for (auto [x, y] : F) {
        if (not g.same(x, y)) {
            ans++;
        } else {
            f.merge(x, y);
        }
    }
    for (auto [x, y] : G) {
        if (not f.same(x, y)) {
            f.merge(x, y);
            ans++;
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