#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
{
    ll x = 0, f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = nc();
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

int n, m;
ll x, cnt;
ll zmax, fumax;
vector<ll> res;

ll solve()
{
    vector<ll> zheng, fu;
    cnt = 0;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        x = read();
        if (x > 0)
            zheng.push_back(x);
        else
            fu.push_back(x);
    }
    if (!zheng.empty())
    {
        sort(zheng.begin(), zheng.end());
        zmax = zheng.back();
    }
    if (!fu.empty())
    {
        sort(fu.begin(), fu.end());
        fumax = fu.front();
        reverse(fu.begin(), fu.end());
    }

    int z1 = zheng.size();
    int f1 = fu.size();
    if (z1 == m)
    {
        return 0;
    }

    if (z1 == 0 and m != 0)
    {
        return -1;
    }
    if (z1 > m and f1 == 0)
    {
        return -1;
    }

    if (z1 < m)
    {
        for (auto &i : fu)
        {
            while (i <= 0)
                i += zmax, cnt++;
            z1++;
            if (z1 == m)
                break;
        }
    }
    else if (z1 > m)
    {
        for (auto &i : zheng)
        {
            while (i > 0)
                i += fumax, cnt++;
            z1--;
            if (z1 == m)
                break;
        }
    }
    return cnt;
}

int main()
{
    int _ = read();
    while (_--)
    {
        res.push_back(solve());
    }
    for (auto &i : res)
    {
        write(i);
        enter;
    }
    return 0;
}