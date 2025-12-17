// https://codeforces.com/problemset/problem/242/E
// 拆位+线段树维护
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 1e5 + 5;

int n, m;
int a[N];

// bit[i] 表示管辖区间有多少元素在第 i 位为 1
// 合并时加起来就行了
struct node
{
    ll l, r, tag;
    vector<int> bit;
} s[N << 2];

void pushdown(ll pos)
{
    if (s[pos].tag)
    {
        s[lst].tag ^= s[pos].tag;
        s[rst].tag ^= s[pos].tag;
        for (int i = 20; ~i; i--)
        {
            if (s[pos].tag & (1 << i))
            {
                s[lst].bit[i] = s[lst].r - s[lst].l + 1 - s[lst].bit[i];
                s[rst].bit[i] = s[rst].r - s[rst].l + 1 - s[rst].bit[i];
            }
        }
        s[pos].tag = 0;
    }
}

void pushup(ll pos)
{
    for (int i = 20; ~i; i--)
    {
        s[pos].bit[i] = s[lst].bit[i] + s[rst].bit[i];
    }
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r, s[pos].bit.resize(21);
    if (l == r)
    {
        for (int i = 20; ~i; i--)
        {
            if (a[l] & (1 << i))
            {
                s[pos].bit[i] = 1;
            }
        }
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, lst);
    build(m + 1, r, rst);
    pushup(pos);
}

void upd(ll x, ll y, ll pos, ll k)
{
    if (x > y)
        swap(x, y);
    if (x <= s[pos].l and s[pos].r <= y)
    {
        s[pos].tag ^= k;
        for (int i = 20; ~i; i--)
        {
            if (k & (1 << i))
            {
                s[pos].bit[i] = s[pos].r - s[pos].l + 1 - s[pos].bit[i];
            }
        }
        return;
    }
    pushdown(pos);
    ll m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        upd(x, y, lst, k);
    if (m < y)
        upd(x, y, rst, k);
    pushup(pos);
    return;
}

ll query(ll x, ll y, ll pos = 1)
{
    if (x > y)
        swap(x, y);
    ll ans = 0;
    if (x <= s[pos].l and s[pos].r <= y)
    {
        for (int i = 20; ~i; i--)
        {
            ans += 1LL * (1 << i) * s[pos].bit[i];
        }
        return ans;
    }
    pushdown(pos);
    ll m = s[pos].l + s[pos].r >> 1;
    if (x <= m)
        ans += query(x, y, lst);
    if (m < y)
        ans += query(x, y, rst);
    return ans;
}

vector<ll> res;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    cin >> m;
    while (m--)
    {
        int opt, x, y, k;
        cin >> opt >> x >> y;
        if (opt == 1)
            res.push_back(query(x, y));
        else if (opt == 2)
        {
            cin >> k;
            upd(x, y, 1, k);
        }
        else
        {
            exit(0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    for (auto &i : res)
    {
        cout << i << endl;
    }
    return 0;
}