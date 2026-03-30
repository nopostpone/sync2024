### f. 树上倍降

> 以下两个做法的复杂度证明见 [oiwiki](https://oi-wiki.org/graph/dsu-on-tree/)。

---

将询问离线，后进行树上启发式合并（dsu on tree）。

复杂度 $O(n\log n + q)$。

```cpp
#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<pair<int, int>>> ask(n);
    for (int i = 0; i < q; i++) {
        int x, d;
        cin >> x >> d;
        x--;
        ask[x].emplace_back(d, i);
    }

    vector<int> siz(n), dep(n);
    [&](this auto &&self, int x, int p) -> void {
        if (p != -1) {
            adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
        }
        siz[x] = 1;
        for (auto &y : adj[x]) {
            dep[y] = dep[x] + 1;
            self(y, x);
            siz[x] += siz[y];
            if (siz[y] > siz[adj[x][0]]) {
                swap(adj[x][0], y);
            }
        }
    } (0, -1);

    vector<i64> f(n + 1);
    vector<i64> ans(q);

    auto add = [&](auto &&self, int x, int t) -> void {
        f[dep[x]] += t * a[x];
        for (auto y : adj[x]) {
            self(self, y, t);
        }
    };
    [&](this auto &&self, int x) -> void {
        for (auto y : adj[x]) {
            if (y != adj[x][0]) {
                self(y);
                add(add, y, -1);
            }
        }
        if (not adj[x].empty()) {
            self(adj[x][0]);
            for (auto y : adj[x]) {
                if (y != adj[x][0]) {
                    add(add, y, 1);
                }
            }
        }
        f[dep[x]] += a[x];
        for (auto [d, i] : ask[x]) {
            ans[i] = f[dep[x] + d];
        }

    } (0);
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
```

---

另有较朴素的启发式合并做法，我们设 $f(x, z)$ 为在 $x$ 子树内的，深度为 $z$ 的所有点权和。在 dfs 的过程中，对于 $x$ 的每个儿子 $y$，将 $f(y)$ 与 $f(x)$ 进行启发式合并。

复杂度为 $O(n \log ^2 n + q)$，比较好写，代码如下。

```cpp
#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<pair<int, int>>> ask(n);
    for (int i = 0; i < q; i++) {
        int x, d;
        cin >> x >> d;
        x--;
        ask[x].emplace_back(d, i);
    }

    vector<int> dep(n);
    vector<map<int, i64>> f(n);

    vector<i64> ans(q);

    [&](this auto &&self, int x, int p) -> void {
        f[x][dep[x]] = a[x];
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }

            dep[y] = dep[x] + 1;
            self(y, x);

            if (f[x].size() < f[y].size()) {
                swap(f[x], f[y]);
            }
            for (auto [d, v] : f[y]) {
                f[x][d] += v;
            }

            f[y].clear();
        }
        for (auto [d, i] : ask[x]) {
            ans[i] = f[x].contains(dep[x] + d) ? f[x][dep[x] + d] : 0;
        }
    } (0, -1);
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}
```
