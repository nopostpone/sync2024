[题目链接](https://www.luogu.com.cn/problem/P10714)

由题意可以知道，星星互相之间没有影响，那么我们可以统计每颗星星的贡献，然后累加求和，问题就转化成了“对于给定位置的星星，由多少种走法可以吃到它”。

规律有点难想，不妨先把星星划分成分成与起点在同一行或同一列，和与起点既不在同一行也不在同一列两类进行讨论。

### 与起点不在同一行，也不在同一列的星星

对于和起点不在同一行或同一列的星星，因为只能走两步，可以再分为先定位到行和先定位到列两种情况。

如果先定位到行，那下一步的目标一定要经过目标，如下图所示，可以走到目标位置，也可以走到底，也就是说从目标位置到边界可以任选一点（图种绿框就是第二步可以选择的终点）。

![pic1](https://img.picui.cn/free/2024/07/08/668b2b39500ef.png)

先定位列再定位行同理，示意图如下。

![pic2](https://img.picui.cn/free/2024/07/08/668b2b3994998.png)

上述两种情况互相独立，因此和起点不在同一行或同一列的星星的贡献就是两者相加的结果。

不妨设 $dx$ 和 $dy$，定义如下：
```cpp
// (x0, y00) 为起点坐标
if (x > x0)
    dx = n - x + 1;
else
    dx = x;
if (y > y00)
    dy = m - y + 1;
else
    dy = y;
```

__从上面两个示意图可以看出，$(dx+dy)$ 即为所求。__

### 与起点在同一行或同一列的星星

对于和起点在同一行或同一列的星星，再分为第一步就吃到，和第二步才吃到两种情况。

第一步就吃到，第二步随便怎么走都可以了，比较好想就步放示意图了，情况数为 $(n+m-2)(dx)$ 或 $(n+m-2)(dy)$。

第一步不吃到，第二步才吃到的示意图如下。第一步可以选白框（除了起点自己）中的点，第二步选择橙框中的点即可保证第二步才吃到星星。情况数为 $(n-dx-1)(dx)$ 或 $(m-dy-1)(dy)$。

![pic3](https://img.picui.cn/free/2024/07/08/668b2b398c507.png)

__综上所述：对于和起点不在同一行与同一列的星星，贡献为 $(dx+dy)$，对于和起点在同一行的星星，贡献为 $(2n+m-dx-3)(dx)$，同一列则贡献为 $(2m+n-dy-3)(dy)$。__

代码如下（记得取模维护）：
```cpp
#include <bits/stdc++.h>
using namespace std;
// 开 long long 就行
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;

ll k, res, x0, y00, n, m, dx, dy, x, y;
const ll p = 1e9 + 7;

void solve()
{
    cin >> n >> m >> k >> x0 >> y00;
    for (ll i = 1; i <= k; i++)
    {
        cin >> x >> y;

        if (x > x0)
            dx = n - x + 1;
        else
            dx = x;
        if (y > y00)
            dy = m - y + 1;
        else
            dy = y;
            
        if (x == x0)
        {
            dy %= p;
            res = (res + ll(dy * (ll(m + n - 3 + m - dy) % p))) % p;
        }
        else if (y == y00)
        {
            dx %= p;
            res = (res + ll(dx * (ll(m + n - 3 + n - dx) % p))) % p;
        }
        else
        {
            dy %= p, dx %= p;
            res = (res + dx + dy) % p;
        }
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
```