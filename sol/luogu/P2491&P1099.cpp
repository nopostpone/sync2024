#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 3e5 + 100;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
{
    int x = 0, f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = nc();
    }
    return x * f;
}
void write(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

struct edge
{
    int v, w;
};

vector<edge> g[N];
int n, s, c, xd, yd;
int dep[N], pre[N], vis[N];
int res = 0x7fffffff;

void dfs(int now, int fa)
{
    pre[now] = fa;
    for (auto &[v, w] : g[now])
    {
        if (v == fa or vis[v])
            continue;
        dep[v] = dep[now] + w;
        if (dep[v] > dep[c])
            c = v;
        dfs(v, now);
    }
}

void solve()
{
    n = read(), s = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    dep[c] = 0, xd = c;
    dfs(c, 0);
    yd = c;
    for (int i = yd, j = yd; i; i = pre[i])
    {
        vis[i] = 1;
        while (dep[j] - dep[i] > s)
            j = pre[j];
        res = min(res, max(dep[i], dep[yd] - dep[j]));
    }
    for (int i = yd; i; i = pre[i])
    {
        dep[i] = 0;
        dfs(i, pre[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        res = max(res, dep[i]);
    }
    write(res);
}

int main()
{
        solve();
    return 0;
}