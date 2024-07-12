// https://www.luogu.com.cn/problem/P3369
// 权值线段树

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
#define enter putchar('\n')
const int N = 1e5 + 100;

int n;
int a[N];

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
        upd(lst, c);
    else
        upd(rst, c);
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

struct Q
{
    int opt;
    int x;
};
vector<Q> q;

void solve()
{
    cin >> n;
    build(1, n, 1);
    q.resize(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i].opt >> q[i].x;
        if (q[i].opt != 4)
            a[++tot] = q[i].x;
    }
    sort(a + 1, a + n + 1);
    for (auto &qq : q)
    {
        if (qq.opt == 1)
            upd(1, lower_bound(a + 1, a + 1 + n, qq.x), 1);
        if (qq.opt == 2)
            upd(1, lower_bound(a + 1, a + 1 + n, qq.x), -1);
    }
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}