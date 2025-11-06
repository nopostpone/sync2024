// https://www.luogu.com.cn/problem/P4588
// 以时间为轴建立线段树
// 每次在后方插入因子，线段树维护区间乘积
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
#define enter putchar('\n')
const int N = 1e5 + 100;

int a[N], n;
ll p;

struct segtree
{
    ll l, r, sum;
} s[N * 4];

void pushup(ll pos)
{
    s[pos].sum = ((s[lst].sum % p) * (s[rst].sum % p)) % p;
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r;
    if (l == r)
    {
        s[pos].sum = 1;
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void upd(ll pos, ll c, ll k)
{
    if (s[pos].l == s[pos].r)
    {
        s[pos].sum = k % p;
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

vector<ll> res;

void solve()
{
    int cnt = 0;
    cin >> n >> p;
    build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        int opt;
        ll m;
        cin >> opt >> m;
        cnt++;
        if (opt == 1)
        {
            upd(1, cnt, m);
        }
        else
        {
            upd(1, cnt, 1);
            upd(1, m, 1);
        }
        res.push_back(s[1].sum % p);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    for (auto &i : res)
    {
        cout << i << endl;
    }
    return 0;
}