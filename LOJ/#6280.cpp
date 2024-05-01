// https://loj.ac/p/6280
// 分块例题：区间修改、区间和查询
// 用数组s存放每个块的和
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int N = 1e7 + 7;
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
ll a[N], b[N], s[N];
struct caozuo
{
    int isq, l, r;
    ll c;
};
vector<caozuo> co;

ll addd(ll a, ll b, ll p)
{
    return (a + b) % p;
}

void update(int l, int r, ll c)
{
    int sid = id[l], eid = id[r];
    if (sid == eid)
    {
        for (int i = l; i <= r; i++)
            a[i] += c, s[sid] += c;
        return;
    }
    for (int i = l; id[i] == sid; i++)
        a[i] += c, s[sid] += c;
    for (int i = sid + 1; i < eid; i++)
        b[i] += c, s[i] += len * c;
    for (int i = r; id[i] == eid; i--)
        a[i] += c, s[eid] += c;
}

ll query(int l, int r, ll p)
{
    ll sum = 0;
    int sid = id[l], eid = id[r];
    if (sid == eid)
    {
        for (int i = l; i <= r; i++)
            sum = addd(sum, a[i] + b[sid], p);
        return sum;
    }
    for (int i = l; id[i] == sid; i++)
        sum = addd(sum, a[i] + b[sid], p);
    for (int i = sid + 1; i != eid; i++)
        sum = addd(sum, s[i], p);
    for (int i = r; id[i] == eid; i--)
        sum = addd(sum, a[i] + b[eid], p);
    return sum;
}

void solve()
{
    n = read(), len = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = read(), id[i] = (i - 1) / len + 1, s[id[i]] += a[i];
    for (int i = 1; i <= n; i++)
        co.push_back(caozuo{read(), read(), read(), read()});
    for (vector<caozuo>::iterator i = co.begin(); i != co.end(); i++)
        if (i->isq)
            write(query(i->l, i->r, i->c + 1)), putchar('\n');
        else
            update(i->l, i->r, i->c);
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