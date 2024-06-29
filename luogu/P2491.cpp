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

int n, s;

void dfs(int now,int fa)
{

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
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}