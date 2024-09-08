初探状压 dp
===
[toc]

状压指状态压缩（`bitmasks`），将一个状态用一个二进制数表示，是非常实用的算法。

状压在 dp 中也有较广的应用。比如某人拿了 A，不拿 B，拿了 C 可以用 `101` 表示，这样将一个状态具象化为一个数，便于表示和转移，有时也可以将阶乘复杂度优化为指数复杂度（对较小的 $n$）。

本文会结合题目介绍状压 dp 的具体实现和优点。由于笔者刚开始学（dp 水太深= =），见到的题型较少，**本文会不断更新**。

## 最短 Hamilton 路径

> [洛谷 P10477](https://www.luogu.com.cn/problem/P10447)

Hamilton 路径的定义为通过图中所有点一次且仅一次（详见 [oiwiki 上的介绍](https://oiwiki.com/graph/hamilton/)）。

现给定有 $n$ 个点的带边权无向图（任意两点都连通），要求从点 $0$ 到点 $n - 1$ 的最短 Hamilton 路径。

```cpp
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr int inf = 2e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector dis(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dis[i][j];
        }
    }
    
    vector dp(1 << n, vector<int>(n, inf));
    dp[1][0] = 0;
    for (int S = 3; S < (1 << n); S += 2) { 
        for (int v = 0; v < n; v++) {
            if ((S >> v) & 1) {
                for (int u = 0; u < n; u++) {
                    dp[S][v] = min(dp[S][v], dp[S - (1 << v)][u] + dis[u][v]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;

    return 0;
}
```


