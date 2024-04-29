// https://www.luogu.com.cn/problem/P3372
// 线段树模板题
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int N = 1e6 + 7;
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

int n, m;
ll a[N], d[N], b[N];
struct caozuo
{
    bool isQuery = 0;
    ll l, r, k = 0;
};
vector<caozuo> co;

void build(ll l, ll r, ll p)
{
    if (l == r)
    {
        d[p] = a[l];
        return;
    }
    ll m = l + ((r - l) >> 1);
    build(l, m, p << 1), build(m + 1, r, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}

void pushdown(ll l, ll r, ll s, ll t, ll p, ll m)
{
    d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
        b[p << 1] += b[p], b[(p << 1) | 1] += b[p],
        b[p] = 0;
}

ll getsum(ll l, ll r, ll s, ll t, ll p)
{
    if (l <= s and r >= t)
        return d[p];
    ll m = s + ((t - s) >> 1);
    if (b[p])
        pushdown(l, r, s, t, p, m);
    ll sum = 0;
    if (l <= m)
        sum += getsum(l, r, s, m, (p << 1));
    if (r > m)
        sum += getsum(l, r, m + 1, t, ((p << 1) | 1));
    return sum;
}

void update(ll l, ll r, ll k, ll s, ll t, ll p)
{
    if (l <= s and r >= t)
    {
        d[p] += (t - s + 1) * k, b[p] += k;
        return;
    }
    ll m = s + ((t - s) >> 1);
    if (b[p])
        pushdown(l, r, s, t, p, m);
    if (l <= m)
        update(l, r, k, s, m, p << 1);
    if (r > m)
        update(l, r, k, m + 1, t, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, n, 1);
    while (m--)
        if (read() == 2)
            co.push_back(caozuo{true, read(), read(), 0});
        else
            co.push_back(caozuo{false, read(), read(), read()});
    for (vector<caozuo>::iterator i = co.begin(); i != co.end(); i++)
        if ((*i).isQuery)
            cout << getsum((*i).l, (*i).r, 1, n, 1) << endl;
        else
            update((*i).l, (*i).r, (*i).k, 1, n, 1);
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