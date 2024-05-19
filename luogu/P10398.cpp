// https://www.luogu.com.cn/problem/P10398
// 思路：https://www.luogu.com.cn/article/bix5nmak
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 2e5 + 100;
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
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

int n, a[N];
string fst = "Alice", lst = "Bob";

bool ck(int x, int y)
{
    if (x == 1)
        return 1;
    if (x == 2)
        return !((a[n - 1] - y) & 1);
    if (a[n - x + 1] - y != 1)
        return !((x + a[n - 1] - y) & 1);
    return !ck(x - 1, y + 1) || !ck(x - 1, y);
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    if (ck(n, 0))
        cout << fst << endl;
    else
        cout << lst << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = read();
    while (_--)
        solve();
    return 0;
}
