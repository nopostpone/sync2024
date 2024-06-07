// https://www.luogu.com.cn/problem/P5057
// 分块
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define qwq                \
    cout << "qwq" << endl; \
    return;
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 1e5 + 100;

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

int len;
int t[N], a[N], id[N];

void update(int l, int r)
{
    int sid = id[l], eid = id[r];
    if (sid == eid)
    {
        for (int i = l; i <= r; i++)
            a[i] ^= 1;
        return;
    }
    for (int i = l; id[i] == sid; i++)
        a[i] ^= 1;
    for (int i = sid + 1; i < eid; i++)
        t[i] ^= 1;
    for (int i = r; id[i] == eid; i--)
        a[i] ^= 1;
}

int query(int x)
{
    return t[id[x]] ? (a[x] ^ 1) : a[x];
}

void solve()
{
    int n = read(), m = read();
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = 0, id[i] = (i - 1) / len + 1;
    while (m--)
        if (read() == 1)
        {
            int l = read(), r = read();
            update(l, r);
        }
        else
            write(query(read())),putchar('\n');
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}