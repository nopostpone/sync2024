// https://www.luogu.com.cn/problem/P3366
// 24.8.8 重写了一下
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

struct Edge {
    int u, v, w;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<Edge> e;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        e.push_back({u, v, w});
    }
    sort(e.begin(), e.end(), [&](Edge A, Edge B) { return A.w < B.w; });

    DSU dsu(n);
    int res = 0;
    int cnt = 0;
    for (auto &&[u, v, w] : e) {
        if (dsu.same(u, v))
            continue;
        dsu.merge(u, v);
        res += w;
        cnt++;
    }
    if (cnt < n - 1)
        cout << "orz" << endl;
    else
        cout << res << endl;

    return 0;
}