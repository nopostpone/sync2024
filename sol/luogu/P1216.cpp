// https://www.luogu.com.cn/problem/P1216
// 从倒数第二层倒着往上走
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 1e3 + 100;
const int inf = 0x3f3f3f3f;

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

int a[N][N];

void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] = read();
    for (int i = n - 1; i; i--)
        for (int j = 1; j <= i; j++)
            a[i][j] = max(a[i][j] + a[i + 1][j], a[i][j] + a[i + 1][j + 1]);
    write(a[1][1]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}