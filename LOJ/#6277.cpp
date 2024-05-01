// https://loj.ac/p/6277
// 数据分块1：区间修改、单点查询
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int N = 1e6 + 7;
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
void write(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

int n, len;
int id[N];
ll a[N], b[N];
struct caozuo
{
    int isq, l, r, c;
};
vector<caozuo> co;

void update(int l, int r, ll c)
{
    int sid = id[l], eid = id[r];
    if (sid == eid)
    {
        for (int i = l; i <= r; i++)
            a[i] += c;
        return;
    }
    for (int i = l; id[i] == sid; i++)
        a[i] += c;
    for (int i = sid + 1; i < eid; i++)
        b[i] += c;
    for (int i = r; id[i] == eid; i--)
        a[i] += c;
}

ll query(int x)
{
    return a[x] + b[id[x]];
}

void solve()
{
    n = read(), len = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = read(), id[i] = (i - 1) / len + 1;
    for (int i = 1; i <= n; i++)
        co.push_back(caozuo{read(), read(), read(), read()});
    for (vector<caozuo>::iterator i = co.begin(); i != co.end(); i++)
    {
        if ((*i).isq)
            write(query(i->r)), putchar('\n');
        else
            update(i->l, i->r, i->c);
    }
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