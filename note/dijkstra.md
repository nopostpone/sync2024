# dijkstra 最短路算法

本文分为原理、实现和优化三个部分。

## 简介，原理和证明

$\text{dijkstra}$ 适用于求单源最短路径，应用场景很广，基本求最短路就能用。但是要注意，在存在负数边权时，该算法不适用。

用很朴素的话说，$\text{dijkstra}$ 从起点开始往外扩展，每次扩展一个点时，会更新这个点的所有邻居，以此实现从近到远，层层扩展，并保证其正确性。

接下来用数学语言描述 $\text{dijkstra}$ 的流程。

- 对于 $G = \langle V, E \rangle$，设 $S$ 表示已找到最短路径的集合，设 $Q = V - S$，表示未找到最短路径的集合。

- 设 $L_i$ 为当前情况下，起点到点 i 的最短距离（$i \in U$）。

- 记起点为 $s$。

先定义 $\text{dijkstra}$ 算法的核心——“松弛”操作：

对于与 $s$ 连通的点 $u$，如果存在一条从 $u$ 到 $v$ 的边，那么从 $s$ 到 $v$ 就有一条路径 $s\rightarrow u\rightarrow v$，这条路径的长度是 $L_u+w(u, v)$。

如果这个值比目前已知的 $L_v$ 的值要小，那么可以用这个值来更新当前 $L_v$。松弛边的操作一直执行到所有的 $L_v$ 都代表从 $s$ 到 $v$ 的最短路径。

$\text{dijkstra}$ 算法维护点集 $S$ 和 $Q$。集合 $S$ 初始状态为空，而后不断从 $Q$ 移动顶点到 $S$。

每次进行移动，被选择的顶点 $u$ 是 $Q$ 中拥有最小的 $L_u$ 值的顶点。当一个顶点 $u$ 从 $Q$ 中转移到了 $S$ 中，需要对 $u$ 的每条出边 $u\rightarrow v$ 进行松驰。

当 $S = V, \ Q = \emptyset$ 时停止，此时 $L$ 即为所求。

下面给出 $\text{dijkstra}$ 正确性的归纳法证明。

- 显然，对上述步骤 2 找到的第一个点 u，$\text{dis}_{u}$ 一定是最优的（即一定是从 s 到 u 的最短路径）

- 假设已用 $\text{dijkstra}$ 算法依次标记了 $v_1, v_2, ..., v_k$ （即标记了 $k$ 个点）。在标记第 k + 1 个点时



## 实现

在代码实现中，步骤与上述数学语言描述的步骤大同小异，大致如下。

1. 若要求点 s 到所有点的最短路，则置 $\text{dis}_{i}$ 表示点 s 到第 i 个点距离。初始化令 $\text{dis}_{s} = 0, \ \text{dis}_{j} = +\infty\ (1 \leq j \leq n, j \neq s)$。

    再置 $\text{vis}_i$ 表示第 i 个点有没有被访问过（最开始都没访问过，全置 0）。

1. 找到未被访问过的点中，到点 s 最近的点 u，将 u 标记为已访问。

1. 遍历点 u 的所有出边，不妨以 $\{u, v, w\}$ 表示从 u 到 v 的，边权为 w 的边，若 $\text{dis}_{u} + w < \text{dis}_v$，则令 $\text{dis}_{v} = \text{dis}_{u} + w$。

1. 回到第二步，直到所有点都被标记过。

对于有 n 个点，m 条边的图，该方法复杂度为 $O(nm)$。

代码如下（模板题 [洛谷 P3371](https://www.luogu.com.cn/problem/P3371) ）

```cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr ll inf = (1LL << 31) - 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, s;
    cin >> n >> m >> s;
    s--;

    vector<vector<pair<int, ll>>> adj;
    adj.assign(n, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    vector<ll> dis(n, inf);
    bitset<10005> vis(0);

    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = 0;
        for (int j = 0; j < n; j++) {
            if (vis[u] || (!vis[j] and dis[j] < dis[u])) {
                u = j;
            }
        }
            vis[u] = 1;
            for (auto &&[v, w] : adj[u]) {
                dis[v] = min<ll>(dis[v], dis[u] + w);
            }
    }

    for (auto &i : dis) {
        cout << i << " ";
    }

    return 0;
}
```

## 优化

```cpp
// https://www.luogu.com.cn/problem/P4779
// dijkstra O((V + E)logE)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const ll inf = (1ll << 31) - 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, s;
    cin >> n >> m >> s;
    s--;
    
    vector<vector<pair<int, ll>>> adj;
    adj.assign(n, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    using pii = pair<ll, int>;
    priority_queue<pii, vector<pii>, greater<>> q;
    bitset<100000> vis(0);
    vector<ll> dis(n, inf);

    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto [D, u] = q.top();
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto &&[v, w] : adj[u]) {
            if (!vis[v] and (dis[u] + w < dis[v])) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }

    for (auto &i : dis) {
        cout << i << " ";
    }

    return 0;
}

```