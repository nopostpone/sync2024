// https://www.luogu.com.cn/problem/P3916
// 很好的dfs例题，反向建边会方便很多
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e5 + 7;

vector<int> g[N];
int res[N];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void dfs(int st, int max)
{
    if (res[st])
        return;
    res[st] = max;
    for (int i = 0; i < g[st].size(); i++)
        dfs(g[st][i], max);
}

void solve()
{
    int n = read(), m = read(), u, v;
    for (int i = 1; i <= m; i++)
        u = read(), v = read(), g[v].push_back(u);
    for (int i = n; i >= 1; i--)
        dfs(i, i);
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}