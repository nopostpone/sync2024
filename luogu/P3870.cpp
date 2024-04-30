// https://www.luogu.com.cn/problem/P3870
// 线段树（也可以用分块做）
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
void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

int n, m;
bitset<N> a;
ll d[N], b[N];
struct caozuo
{
    int isQuery = 0;
    int l, r;
};
vector<caozuo> co;

inline void pushdown(ll l, ll r, ll p, ll m)
{
    b[(p << 1) | 1] ^= 1, b[p << 1] ^= 1;
    d[p << 1] = (m - l + 1) - d[p << 1];
    d[(p << 1) | 1] = (r - m) - d[(p << 1) | 1];
    b[p] = 0;
}

ll getsum(ll l, ll r, ll s, ll t, ll p)
{
    if (l <= s and r >= t)
        return d[p];
    ll m = s + ((t - s) >> 1);
    if (b[p])
        pushdown(s, t, p, m);
    ll sum = 0;
    if (l <= m)
        sum += getsum(l, r, s, m, (p << 1));
    if (r > m)
        sum += getsum(l, r, m + 1, t, ((p << 1) | 1));
    return sum;
}

void update(ll l, ll r, ll s, ll t, ll p)
{
    if (l <= s and r >= t)
    {
        d[p] = (t - s + 1) - d[p], b[p] ^= 1;
        return;
    }
    ll m = s + ((t - s) >> 1);
    if (b[p])
        pushdown(s, t, p, m);
    if (l <= m)
        update(l, r, s, m, p << 1);
    if (r > m)
        update(l, r, m + 1, t, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}

void solve()
{
    n = read(), m = read();
    while (m--)
        co.push_back(caozuo{read(), read(), read()});
    for (vector<caozuo>::iterator i = co.begin(); i != co.end(); i++)
        if ((*i).isQuery)
            write(getsum((*i).l, (*i).r, 1, n, 1)), putchar(endl);
        else
            update((*i).l, (*i).r, 1, n, 1);
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