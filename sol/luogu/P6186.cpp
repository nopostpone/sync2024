// https://www.luogu.com.cn/problem/P1908
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
#define enter putchar('\n')
const int N = 5e5 + 100;

int n;
int a[N], b[N];
ll p;

struct segtree
{
    ll l, r, sum;
} s[N * 4];

void pushup(ll pos)
{
    s[pos].sum = s[lst].sum + s[rst].sum;
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r;
    if (l == r)
    {
        s[pos].sum = 0;
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void upd(ll pos, ll c, int k)
{
    if (s[pos].l == s[pos].r)
    {
        s[pos].sum += k;
        return;
    }
    ll m = s[pos].l + s[pos].r >> 1;
    if (c <= m)
        upd(lst, c, k);
    else
        upd(rst, c, k);
    pushup(pos);
    return;
}

ll query(ll pos, ll x, ll y)
{
    if (x <= s[pos].l and s[pos].r <= y)
    {
        return s[pos].sum;
    }
    ll m = s[pos].l + s[pos].r >> 1;
    ll ans = 0;
    if (x <= m)
        ans += query(lst, x, y);
    if (m < y)
        ans += query(rst, x, y);
    return ans;
}

ll res;
int m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(b + 1, b + n + 1);
    build(1, n, 1);
    while (m--)
    {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1)
        {
        }
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