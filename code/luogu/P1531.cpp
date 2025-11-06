// https://www.luogu.com.cn/problem/P1531
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define qwq                \
    cout << "qwq" << endl; \
    return;
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 2e5 + 100;

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

struct SegTree
{
    int l, r, big;
    SegTree()
    {
        big = 0;
    }
} s[N * 4];

int a[N];

void pushup(int pos)
{
    s[pos].big = max(s[lst].big, s[rst].big);
}

void pushdown(int pos)
{
    return;
}

void build(int l, int r, int pos)
{
    s[pos].l = l, s[pos].r = r;
    if (l == r)
    {
        s[pos].big = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lst);
    build(mid + 1, r, rst);
    pushup(pos);
    return;
}

void update(int pos, int x, int y)
{
    if (s[pos].l == s[pos].r)
    {
        if (s[pos].big < y)
            s[pos].big = y;
        return;
    }
    int mid = (s[pos].l + s[pos].r) >> 1;
    update(x <= mid ? lst : rst, x, y);
    pushup(pos);
}

int query(int pos, int x, int y)
{
    if (s[pos].l >= x and y >= s[pos].r)
        return s[pos].big;
    int mid = (s[pos].l + s[pos].r) >> 1;
    int res = -1e9;
    if (x <= mid)
        res = max(res, query(lst, x, y));
    if (y > mid)
        res = max(res, query(rst, x, y));
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (m--)
    {
        char qry;
        int x, y;
        cin >> qry >> x >> y;
        if (qry == 'Q')
            cout << query(1, x, y) << endl;
        else
            update(1, x, y);
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