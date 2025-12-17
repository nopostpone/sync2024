#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int64_t read()
{
    int x = 0, f = 1;
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

int n;
int c[N];
bool a[N], b[N];
vector<int> ji, ou;
int res[N];

void solve()
{
    memset(res, -1, sizeof(res));
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        if (x & 1)
            a[i] = 1;
        else
            a[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
            b[i] = !b[i - 1], ji.push_back(i);
        else
            b[i] = b[i - 1], ou.push_back(i);
    }
    int huan = min(ji.size(), ou.size());
    int s = 0;
    for (int i = 1; i <= n; i++)
        s += b[i] ? 1 : 0;
    res[s] = 0;
    for (auto &l : ji)
    {
        for (auto &r : ou)
        {
            if (l > r)
                swap(l, r);
            int s2 = s + r - l;
            for (int i = l; i < r; i++)
                if (b[i])
                    s2 -= 2;
            if (res[s2] == -1)
                res[s2] = c[l] + c[r];
            else
                res[s2] = min(res[s2], c[l] + c[r]);
        }
    }
    for (int i = 0; i <= n; i++)
        write(res[i]), putchar(' ');
    enter;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = read();
    while (_--)
        solve();
    return 0;
}