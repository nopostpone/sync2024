// https://www.luogu.com.cn/problem/P1276
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1e4 + 7;

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

int n, m, opt, l, r;
bitset<N> a, b;
ll res1, res2;

void solve()
{
    n = read(), m = read();
    a.set(), b.set();
    while (m--)
    {
        opt = read(), l = read(), r = read();
        if (opt)
            for (int i = l; i <= r; i++)
                a.set(i);
        else
            for (int i = l; i <= r; i++)
                res2 += a[i] xor b[i], a.reset(i), b.reset(i);
    }
    for (int i = 0; i <= n; i++)
        res1 += a[i] xor b[i];
    write(res1), putchar('\n'), write(res2);
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