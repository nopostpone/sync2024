#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
#define enter putchar('\n')
const int N = 1e6 + 100;

int n, m;
ll a[N];

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

ll qrank(ll pos, ll x, ll y)
{
    if (x <= s[pos].l and s[pos].r <= y)
    {
        return s[pos].sum;
    }
    ll m = s[pos].l + s[pos].r >> 1;
    ll ans = 0;
    if (x <= m)
        ans += qrank(lst, x, y);
    if (m < y)
        ans += qrank(rst, x, y);
    return ans;
}

ll qnum(ll pos, ll x)
{
    if (s[pos].l == s[pos].r)
        return s[pos].l;
    if (x <= s[lst].sum)
        return qnum(lst, x);
    else
        return qnum(rst, x - s[lst].sum);
}

struct Q
{
    int opt;
    int x;
};
vector<Q> q;

ll last;
ll tmpres;
ll res;

void solve()
{
    cin >> n >> m;
    q.resize(n + m);
    int tot = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i].opt >> q[i].x;
        if (q[i].opt != 4)
            a[++tot] = q[i].x;
    }
    sort(a + 1, a + tot + 1);
    n = unique(a + 1, a + tot + 1) - a - 1;
    build(1, n, 1);
    for (auto &qq : q)
    {
        int id = 0;
        qq.x ^= last;
        if (qq.opt != 4)
            id = lower_bound(a + 1, a + 1 + n, qq.x) - a;
        if (qq.opt == 1)
            upd(1, id, 1);
        else if (qq.opt == 2)
            upd(1, id, -1);
        else if (qq.opt == 3)
            tmpres = (id > 1 ? qrank(1, 1, id - 1) + 1 : 1);
        else if (qq.opt == 4)
            tmpres = a[qnum(1, qq.x)];
        else if (qq.opt == 5)
        {
            int rk = qrank(1, 1, id - 1);
            tmpres = a[qnum(1, rk)];
        }
        else if (qq.opt == 6)
        {
            int rk = qrank(1, 1, id) + 1;
            tmpres = a[qnum(1, rk)];
        }
        if (qq.opt >= 3)
        {
            last = tmpres;
            res ^= tmpres;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    cout << res << endl;
    return 0;
}