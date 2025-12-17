#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

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

    vector<array<int, 4>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        edges[i] = {w, u, v, i};
    }

    DSU dsu(n);
    ranges::sort(edges);

    i64 ans = 0;

    int cnt = n - 1;
    vector<int> edges_ans;
    for (auto [w, u, v, id] : edges) {
        if (dsu.same(u, v)) {
            continue;
        }
        cnt--;
        if (w == 0) {
            dsu.merge(u, v);
            edges_ans.push_back(id);
            continue;
        }
        if (cnt < k) {
            break;
        }

        dsu.merge(u, v);
        edges_ans.push_back(id);
        ans += w;
    }

    vector<array<int, 2>> add;
    for (int i = 0; i < n - 1; i++) {
        if (not dsu.same(i, i + 1)) {
            add.push_back({i, i + 1});
            edges_ans.push_back(m + add.size() - 1);
            dsu.merge(i, i + 1);
            ans++;
        }
    }

    cout << add.size() << "\n";
    for (auto [u, v] : add) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
    cout << ans << "\n";
    for (auto e : edges_ans) {
        cout << e + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}

/*
3
5 6 2
1 2 3
2 3 5
1 4 7
4 2 4
5 4 8
3 5 1
4 5 100
1 2 2
2 3 0
2 4 0
4 1 1
3 4 3
3 2 0
1 2 100
2 3 100

*/