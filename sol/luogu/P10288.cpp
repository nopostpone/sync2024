// https://www.luogu.com.cn/problem/P10288
// 离散化模板题
#include <bits/stdc++.h>
using namespace std;
#define enter (putchar('\n'))
#define space (putchar(' '))
#define endl '\n'
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
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
void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

int n, bb, q;
int a[N], b[N];
vector<int> s[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = read();
    q = read();
    sort(b + 1, b + n + 1), bb = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + bb + 1, a[i]) - b, s[a[i]].push_back(i);
    while (q--)
    {
        int l = read(), r = read(), x = read();
        int k = lower_bound(b + 1, b + bb + 1, x) - b;
        if (b[k] != x)
        {
            write(0), enter;
            continue;
        }
        vector<int>::iterator i = lower_bound(s[k].begin(), s[k].end(), l),
                              j = --upper_bound(s[k].begin(), s[k].end(), r);
        write(j - i + 1), enter;
    }
    for (int i = 1; i <= n; i++)
        s[i].clear();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    _ = read();
    while (_--)
        solve();
    return 0;
}