// https://www.luogu.com.cn/problem/P3373
// 线段树模板题
#include <bits/stdc++.h>
#define endl '\n'
#define qwq putchar('q');
using ll = long long;
using namespace std;
const int N = 1e5 + 7;
inline int read()
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

int n, m, P, a[N];
struct Segment_Tree
{
    ll sum, add, mul, l, r;
} s[N * 4];
struct caozuo
{
    ll cz, x, y, k = 0;
};
vector<caozuo> co;

void update(ll pos)
{
    s[pos].sum = (s[pos << 1].sum + s[pos << 1 | 1].sum) % P;
}

void build(ll l, ll r, ll pos)
{
    s[pos].l = l, s[pos].r = r, s[pos].mul = 1;
    if (l == r)
    {
        s[pos].sum = a[l] % P;
        return;
    }
    ll m = l + ((r - l) >> 1);
    build(l, m, pos << 1);
    build(m + 1, r, pos << 1 | 1);
    update(pos);
    return;
}

void pushdown(ll pos)
{
    if (s[pos].add == 0 and s[pos].mul == 1)
        return;
    ll nxt = pos << 1, nxt2 = pos << 1 | 1;
    s[nxt].sum = (s[nxt].sum * s[pos].mul + s[pos].add * (s[nxt].r - s[nxt].l + 1)) % P,
    s[nxt2].sum = (s[nxt2].sum * s[pos].mul + s[pos].add * (s[nxt2].r - s[nxt2].l + 1)) % P,
    s[nxt].mul = (s[nxt].mul * s[pos].mul) % P,
    s[nxt2].mul = (s[nxt2].mul * s[pos].mul) % P,
    s[nxt].add = (s[nxt].add * s[pos].mul + s[pos].add) % P,
    s[nxt2].add = (s[nxt2].add * s[pos].mul + s[pos].add) % P,
    s[pos].add = 0, s[pos].mul = 1;
}

void add(ll pos, ll l, ll r, ll k)
{
    if (l <= s[pos].l and r >= s[pos].r)
    {
        s[pos].add = (s[pos].add + k) % P;
        s[pos].sum = (s[pos].sum + k * (s[pos].r - s[pos].l + 1)) % P;
        return;
    }
    pushdown(pos);
    ll m = s[pos].l + ((s[pos].r - s[pos].l) >> 1);
    if (l <= m)
        add(pos << 1, l, r, k);
    if (r > m)
        add(pos << 1 | 1, l, r, k);
    update(pos);
}
void mul(ll pos, ll l, ll r, ll k)
{
    if (k == 1)
        return;
    if (l <= s[pos].l and r >= s[pos].r)
    {
        s[pos].add = (s[pos].add * k) % P;
        s[pos].mul = (s[pos].mul * k) % P;
        s[pos].sum = (s[pos].sum * k) % P;
        return;
    }
    pushdown(pos);
    ll m = s[pos].l + ((s[pos].r - s[pos].l) >> 1);
    if (l <= m)
        mul(pos << 1, l, r, k);
    if (r > m)
        mul(pos << 1 | 1, l, r, k);
    update(pos);
}
ll query(ll pos, ll l, ll r)
{
    if (l <= s[pos].l and r >= s[pos].r)
        return s[pos].sum;
    pushdown(pos);
    ll ans = 0;
    ll m = s[pos].l + ((s[pos].r - s[pos].l) >> 1);
    if (l <= m)
        ans = (ans + query(pos << 1, l, r)) % P;
    if (r > m)
        ans = (ans + query(pos << 1 | 1, l, r)) % P;
    return ans;
}

void solve()
{
    n = read(), m = read(), P = read();
    for (int i = 1; i <= n; i++)
        a[i] = read() % P;
    while (m--)
    {
        int tmp = read();
        if (tmp == 3)
            co.push_back(caozuo{3, read(), read(), 0});
        else
            co.push_back(caozuo{tmp, read(), read(), read()});
    }
    build(1, n, 1);
    // for(int i=1;i<=10;i++)
    //     cout<<s[i].sum<<endl;
    for (auto i = co.begin(); i != co.end(); i++)
        if (i->cz == 3)
            cout << query(1, i->x, i->y) << endl;
        else if (i->cz == 2)
            add(1, i->x, i->y, i->k);
        else
            mul(1, i->x, i->y, i->k);
    cout << endl;
    // for(int i=1;i<=10;i++)cout<<s[i].sum<<endl;
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