// P1438
// https://www.luogu.com.cn/problem/P1438
// 维护两个线段树
#include <bits/stdc++.h>
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
#define qwq cout << "qwq" << '\n'
using ll = long long;
using namespace std;
const int N = 1e5 + 7;
inline ll read()
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

int n, m, a[N], op;
struct Segment_Tree
{
    ll tk = 0, td = 0, l = 0, r = 0, id = 0;
} s[N * 4];

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r;
    if (l == r)
    {
        s[pos].id = l;
        return;
    }
    ll m = l + ((r - l) >> 1);
    build(l, m, lst);
    build(m + 1, r, rst);
}

void pushdown(ll pos)
{
    if (s[pos].tk == 0 and s[pos].td == 0)
        return;
    s[lst].tk += s[pos].tk, s[rst].tk += s[pos].tk;
    s[lst].td += s[pos].td, s[rst].td += s[pos].td;
    s[pos].tk=0,s[pos].td=0;
}

void update(ll pos, ll x, ll y, ll k, ll d)
{
    if (s[pos].l >= x and s[pos].r <= y)
    {
        s[pos].tk += k - d * x, s[pos].td += d;
        return;
    }
    pushdown(pos);
    ll m = (s[pos].l + s[pos].r) >> 1;
    if (x <= m)
        update(lst, x, y, k, d);
    if (y > m)
        update(rst, x, y, k, d);
    return;
}

void query(ll pos, ll x)
{
    if (s[pos].l == s[pos].r)
    {
        cout << a[s[pos].id] + s[pos].tk + s[pos].td*s[pos].id << endl;
        return;
    }
    pushdown(pos);
    ll m = (s[pos].l + s[pos].r) >> 1;
    if (x <= m)
        query(lst, x);
    else
        query(rst, x);
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, n, 1);
    while (m--)
    {
        op = read();
        if (op == 1)
        {
            ll x = read(), y = read(), k = read(), d = read();
            update(1, x, y, k, d);
        }
        else
            query(1, read());
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        solve();
    return 0;
}