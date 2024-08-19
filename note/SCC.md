# SCC 强连通分量

> 在求解 SCC 的方法中，本文只介绍 tarjan 算法。

## 定义

有向图 $G$ 强连通，当且仅当 $G$ 中的任意两个点连通。

强连通分量（Strongly Connected Components，SCC）是指极大的强连通子图。

## 应用

朴素地看，在一个 SCC 内，任意两个点都能互相到达，因此我们可以把 SCC 看成一个由很多点组成的“点”，这也就是求出 SCC 后的一大应用——缩点。

以具体场景举例：

> 题目为 [[USACO5.3] Network of Schools](https://www.luogu.com.cn/problem/P2746)

一些学校连入一个电脑网络。那些学校已订立了协议：每个学校都会给其它的一些学校分发软件。注意即使 $B$ 在 $A$ 学校的分发列表中，$A$ 也不一定在 $B$ 学校的列表中。解决两个问题：

- 起始至少多少个学校需要接受新软件，才能让网络中的学校都用上新软件？

- 最少需要增加几个扩展，使得不论我们给哪个学校发送新软件，它都会到达其余所有的学校（一个扩展就是在一个学校的接收学校列表中引入一个新成员）？

---

现在我们知道了 SCC 的概念，可以想一下 SCC 在这个题目里有什么样的性质。

显然，对于一个 SCC，任意两点之间均能到达，那么我只需要对这个 SCC 中任意一个点发送一个软件，其中所有的点都能收到了，也就是 SCC 可以“缩”成一个点，即上文提到的“缩点”。

我们将所有的 SCC 都进行缩点，最后会得到一个有向无环图（可以用反证法证明一定没有环）。对于最后得到的图，点表示 SCC，边表示 SCC 之间的联系。

举个例子，一个图中有四个点 $A,B,C,D$，边为 $A\rightarrow C, B\rightarrow D, A\leftrightarrow B$。那么图中的 SCC 为 $\{A, B\}, \{C\}, \{D\}$。缩点之后的边就表示为 $ \{A, B\} \rightarrow \{C\}, \ \{A, B\} \rightarrow \{D\}$。

现在再回看这两个问题：

第一个问题，对于每个 SCC，若它入度不为 0（即有其他 SCC 连向它），则不需要发送软件，否则需要发送，原因显然。

第二个问题就是要使整个图成为 SCC，那么对于该问题最优的策略是什么呢？不妨也从出度和入度的角度想一想。

我们知道缩点之后形成的图一定不存在环，也就是说一定存在点入度或出度为 0。假设经过一些操作之后，所有点的入度和出度均不为 0，那么这个图就可以再缩成一个点，即整张图为一个 SCC，也就是该问题的目标。

因此我们可以争取达到以上条件，显然最优的策略就是尽量将出度为 0 的点连向入度为 0 的点，因为只有这样能一次消灭两个 0。

分析之后，我们知道了，这个题目实质上要我们求的是：

对于一个**有向图** $G$，进行 SCC 缩点后，

- 入度为 0 的点的数量。

- 入度为 0 的点数量和出度为 0 的点数量的较大者。

假设我们已经知道怎么求 SCC 了，现在我们得到了 `bel` 数组，表示每个点所属的 SCC 编号，那么对每个 SCC 分别统计一下入度和出度即可，核心代码如下。

```cpp
// cnt 为 SCC 的数量
vector<int> in(cnt), out(cnt);

for (int u = 0; u < n; u++) {
    for (auto v : adj[u]) {
        if (bel[u] == bel[v])
            continue;
        out[bel[u]]++;
        in[bel[v]]++;
    }
}

int A = 0, B = 0;
for (int i = 0; i < cnt; i++) {
    A += in[i] == 0;
    B += out[i] == 0;
}
cout << A << "\n"
     << (cnt == 1 ? 0 : std::max(A, B));
```

## Tarjan 算法求 SCC

知道了 SCC 的应用，现在我们可以来看看如何求 SCC 了。

这块 oiwiki 写得详尽且生动，我直接摘抄过来了，做了一些小改动。

---

如果结点 $u$ 是某个强连通分量在搜索树中遇到的第一个结点，那么这个强连通分量的其余结点肯定是在搜索树中以 $u$ 为根的子树中。结点 $u$ 被称为这个强连通分量的根。

反证法：假设有个结点 $v$ 在该强连通分量中但是不在以 $u$ 为根的子树中，那么 $u$ 到 $v$ 的路径中肯定有一条离开子树的边。但是这样的边只可能是横叉边或者反祖边，然而这两条边都要求指向的结点已经被访问过了，这就和 $v$ 不在以 $u$ 为根的子树中矛盾了。得证。

Tarjan 算法基于对图进行 dfs。我们视每个连通分量为搜索树中的一棵子树，在搜索过程中，维护一个栈，每次把搜索树中尚未处理的节点加入栈中。

在 Tarjan 算法中为每个结点 $u$ 维护了以下几个变量：

1.  $\text{dfn}_u$：深度优先搜索遍历时结点 $u$ 被搜索的次序。
2.  $\text{low}_u$：在 $u$ 的子树中能够回溯到的最早的已经在栈中的结点。设以 $u$ 为根的子树为 $\text{Subtree}_u$。$\text{low}_u$ 定义为以下结点的 $\text{dfn}$ 的最小值：$\text{Subtree}_u$ 中的结点；从 $\text{Subtree}_u$ 通过一条不在搜索树上的边能到达的结点。

一个结点的子树内结点的 dfn 都大于该结点的 dfn。

从根开始的一条路径上的 dfn 严格递增，low 严格非降。

按照深度优先搜索算法搜索的次序对图中所有的结点进行搜索，维护每个结点的 `dfn` 与 `low` 变量，且让搜索到的结点入栈。每当找到一个强连通元素，就按照该元素包含结点数目让栈中元素出栈。在搜索过程中，对于结点 $u$ 和与其相邻的结点 $v$（$v$ 不是 $u$ 的父节点）考虑 3 种情况：

1.  $v$ 未被访问：继续对 $v$ 进行深度搜索。在回溯过程中，用 $\text{low}_v$ 更新 $\text{low}_u$。因为存在从 $u$ 到 $v$ 的直接路径，所以 $v$ 能够回溯到的已经在栈中的结点，$u$ 也一定能够回溯到。
2.  $v$ 被访问过，已经在栈中：根据 low 值的定义，用 $\text{dfn}_v$ 更新 $\text{low}_u$。
3.  $v$ 被访问过，已不在栈中：说明 $v$ 已搜索完毕，其所在连通分量已被处理，所以不用对其做操作。

将上述算法写成伪代码：


```c
TARJAN_SEARCH(int u)
    vis[u]=true
    low[u]=dfn[u]=++dfncnt
    push u to the stack
    for each (u,v) then do
        if v hasn't been searched then
            TARJAN_SEARCH(v) // 搜索
            low[u]=min(low[u],low[v]) // 回溯
        else if v has been in the stack then
            low[u]=min(low[u],dfn[v])
```

对于一个连通分量图，我们很容易想到，在该连通图中有且仅有一个 $u$ 使得 $\text{dfn}_u=\text{low}_u$。该结点一定是在深度遍历的过程中，该连通分量中第一个被访问过的结点，因为它的 dfn 和 low 值最小，不会被该连通分量中的其他结点所影响。

因此，在回溯的过程中，判定 $\text{dfn}_u=\text{low}_u$ 是否成立，如果成立，则栈中 $u$ 及其上方的结点构成一个 SCC。

---

对于之前所讲的例题，在学会求解 SCC 之后，就能写出完整的代码了。

<details>

```cpp
// 从 jls 的板子改的
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector adj(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        j--;
        while (~j) {
            adj[i].push_back(j);
            cin >> j;
            j--;
        }
    }

    vector<int> dfn(n, -1), low(n), bel(n, -1), stk;
    int cur = 0;
    int cnt = 0;

    function<void(int)> dfs = [&](int u) {
        // 搜索
        dfn[u] = low[u] = cur++;
        stk.push_back(u);

        for (auto v : adj[u]) {
            if (dfn[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (bel[v] == -1) {
                low[u] = min(low[u], low[v]);
            }
        }
        // 回溯
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.back();
                bel[v] = cnt;
                stk.pop_back();
            } while (v != u);
            cnt++;
        }
    };

    for (int i = 0; i < n; i++) {
        if (dfn[i] == -1) {
            dfs(i);
        }
    }

    vector<int> in(cnt), out(cnt);

    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) {
            if (bel[u] == bel[v])
                continue;
            out[bel[u]]++;
            in[bel[v]]++;
        }
    }

    int A = 0, B = 0;
    for (int i = 0; i < cnt; i++) {
        A += in[i] == 0;
        B += out[i] == 0;
    }
    cout << A << "\n"
         << (cnt == 1 ? 0 : std::max(A, B));
    return 0;
}
```

</details>

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

—— $2024.8.20$