// https://www.luogu.com.cn/problem/P5461
// 比较经典的递归例题
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e4 + 500;

int n = 1;
bool m[N][N];

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

void shemian(int length, int x, int y)
{
    if (length % 2 != 0)
        return;
    int tmplen = length >> 1;
    for (int i = x; i <= x + tmplen - 1; i++)
        for (int j = y; j <= y + tmplen - 1; j++)
            m[i][j] = 0;
    shemian(tmplen, x + tmplen, y);
    shemian(tmplen, x, y + tmplen);
    shemian(tmplen, x + tmplen, y + tmplen);
}

void solve()
{
    int n1 = read();
    n = 1;
    for (int i = 1; i <= n1; i++)
        n *= 2;
    memset(m, 1, sizeof(m));
    shemian(n, 1, 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << m[i][j] << " \n"[j == n];
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