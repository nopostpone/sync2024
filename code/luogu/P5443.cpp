#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct DSU {
    std::vector<std::pair<int &, int>> his;
    std::vector<int> f, siz;
    
    DSU () {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    void set(int &a, int b) {
        his.emplace_back(a, a);
        a = b;
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x];
        }
        return x;
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (siz[x] < siz[y]) {
            std::swap(x, y);
        }
        set(siz[x], siz[x] + siz[y]);
        set(f[y], x);
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return siz[find(x)];
    }
    int cur() {
        return his.size();
    }
    void rollback(int t) {
        while (his.size() > t) {
            auto [x, y] = his.back();
            x = y;
            his.pop_back();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    struct Edge {
        int u, v, d, i;
    };

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].d;
        edges[i].u--;
        edges[i].v--;
        edges[i].i = i;
    }

    int q;
    cin >> q;

    const int B = 800;

    vector<pair<int, int>> ans;

    vector<array<int, 3>> que, mod;
    que.reserve(q);
    mod.reserve(q);

    auto solve = [&]() {
        if (que.empty()) {
            return;
        }
        auto e = edges;
        ranges::sort(e, [](auto a, auto b) {
            return a.d > b.d;
        });
        ranges::sort(que, greater());

        DSU dsu(n);

        vector<bool> vis(m);
        vector<int> todo;
        for (auto [_, b, __] : mod) {
            vis[b] = true;
            todo.push_back(b);
        }

        int i = 0;
        vector<int> f(m);
        for (auto [w, s, j] : que) {
            while (i < m and e[i].d >= w) {
                if (vis[e[i].i]) {
                    i++;
                    continue;
                }
                dsu.merge(e[i].u, e[i].v);
                i++;
            }
            for (auto b : todo) {
                f[b] = edges[b].d;
            }
            
            int his = dsu.cur();
            for (auto [r, b, t] : mod) {
                if (t < j) {
                    f[b] = r;
                } else {
                    break;
                }
            }
            for (auto b : todo) {
                if (f[b] >= w) {
                    dsu.merge(edges[b].u, edges[b].v);
                }
            }
            ans.emplace_back(j, dsu.size(s));
            dsu.rollback(his);
        }
        
        que.clear();

        for (auto [r, b, _] : mod) {
            edges[b].d = r;
        }
        mod.clear();
    };

    for (int i = 0; i < q; i++) {
        int o, x, y;
        cin >> o >> x >> y;
        x--;
        if (o == 2) {
            que.push_back({y, x, i});
        } else {
            mod.push_back({y, x, i});
        }

        if (i % B == 0) {
            solve();
        }
    }
    solve();

    ranges::sort(ans);
    for (auto [_, x] : ans) {
        cout << x << "\n";
    }

    return 0;
}