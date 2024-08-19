# SCC

## 定义

有向图 $G$ 强连通，当且仅当 $G$ 中的任意两个点连通。

强连通分量（Strongly Connected Components，SCC）是指极大的强连通子图。

## 应用

朴素地看，在一个 SCC 内，任意两个点都能互相到达，因此我们可以把 SCC 看成一个由很多点组成的“点”，这也就是求出 SCC 后的一大应用——缩点。

以具体场景举例：

> 题目为 [[USACO5.3] Network of Schools](https://www.luogu.com.cn/problem/P2746)

给出一个**有向图** $G$，解决两个问题：

- 要使整个图中任意两点均连通（即整个图成为 SCC），最少要连多少边？

- 






## Tarjan 算法求 SCC

## 模板

[_jls_](https://codeforces.com/profile/jiangly) 的板子还是太好用了.jpg

```cpp
struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }
};
```

## 参考

[强连通分量 - oiwiki](https://oiwiki.com/graph/scc/)