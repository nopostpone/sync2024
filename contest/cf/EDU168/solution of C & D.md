# C

[题目链接](https://codeforces.com/contest/1997/problem/C)

一道比较有趣的贪心题。

因为挖去的是奇数位置，且给出的序列一定是合法的，也就是说序列最后一个元素一定是 `)`，我们不妨从右边往左边推演，找找规律。

由于最后一个元素是确定的，可以先对倒数第三个元素分类讨论一下。

假如序列长这样：

```
...... ) _ )
```

为了使距离之和最短，横线上显然填 `(`。

假如是这样：

```
...... ( _ )
```

由于要保证合法性，横线上只能填 `)` 了，那么属于最后一个元素的 `(` 就得再往前找空位插。

可以设想一下，如果前面一直是 `(`，那么就一直没地方插入，必须得再碰到一个 `)` 才可以。

再次碰到 `)` 之后，策略就回到了碰到最开始的状态。

用双指针实现即可。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    int dis = 0;
    int lpos = n - 3;
    int rpos = n - 1;

    while (true) {
        // 如果碰到 ‘)’，回到最初的策略
        if (s[lpos] == ')') {
            dis += rpos - lpos - 1;
            rpos = lpos;
        } else {
            dis++;
        }
        // 每次往前跳两格
        lpos -= 2;
        // 如果 lpos 变成负数（-1）了，说明走到头了，最开始的位置插上 '('，然后退出循环
        if (lpos < 0) {
            dis += rpos - lpos - 1;
            break;
        }
    }

    cout << dis << endl;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
```

# D

[题目链接](https://codeforces.com/contest/1997/problem/D)

一道比较有趣的贪心题。

由题意，可以先产生一个比较模糊的想法：由于根节点 + 1，树上其他点都会 - 1，那么我们能不能从叶子节点一层层往上爬，使所有点尽可能平均一下呢？

不妨假想一个最简单的情形：一个非根节点，有两个子节点，而且子节点都是叶节点。做以下分类讨论：

__第一种情况：__ 两个子节点权值都比自己大。那么要实现“平均”，我们可以不断让自身 + 1，让子节点 - 1，让这三个点的最小值最大。

__第二种情况：__ 存在子节点权值比自己小。这时候就不能再让子节点继续变小了，于是我们就不进行操作。

在决策完成后，这个点的子树就可以用子树中的最小值来表示了，因此对每个非根节点，我们都只需要将它的子节点纳入判断范围，由此实现了层层上推至根节点。

一次树上 dfs 获取深度与点的双向映射即可。

[赛时代码](https://codeforces.com/contest/1997/submission/273583908)比较丑陋，删去了一些没必要的东西，如下。

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

constexpr int inf = 2e9;

// adj 为邻接表（在 dfs 过程中删去父节点，因此也能视作存放子节点）
// rdep 作用是通过深度找点

std::vector<int> dep, parent;
std::vector<std::vector<int>> adj, rdep;
int maxdep;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs1(int u) {
    if (parent[u] != -1) {
        adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
    }
    for (auto &v : adj[u]) {
        parent[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
    }
    maxdep = max(dep[u], maxdep);
    rdep[dep[u]].push_back(u);
}

void work(int root = 0) {
    dep[root] = 0;
    parent[root] = -1;
    dfs1(root);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    dep.resize(n + 1);
    parent.resize(n + 1);
    adj.assign(n + 1, {});
    rdep.assign(n + 1, {});
    maxdep = -inf;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int j;
        cin >> j;
        addEdge(j, i);
    }
    work(1);

    queue<int> qu;
    // 从深到浅依次入队，不包含最深层的点（因为已经确定是叶子节点）和根节点
    for (int d = maxdep - 1; d; d--) {
        for (auto i : rdep[d]) {
            qu.push(i);
        }
    }
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        int mn = inf;
        for (auto &v : adj[u]) {
            mn = min(a[v], mn);
        }
        // 如果 mn 没动，说明这个点自己是叶子节点
        if (mn != inf) {
            if (mn < a[u]) {
                a[u] = mn;
            } else {
                a[u] = a[u] + mn >> 1;
            }
        }
    }
    // 根节点直接加 mn 即可
    int mn = inf;
    for (auto i : adj[1]) {
        mn = min(a[i], mn);
    }

    cout << a[1] + mn << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
```