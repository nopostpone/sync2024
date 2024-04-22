// B3966
// https://www.luogu.com.cn/problem/B3966
// 比赛的时候脑子糊了，忘记答案能是两位数，而采用getline然后一个一个读，然后寄
// 就差这道题AK
// 快读确实好用.jpg
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e3 + 100;

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

int c[N][5010];
bool answ[N][5010];
ll res = 0;
int n, m;

void chuli(int i)
{
    for (int j = 1; j <= m; j++)
        if (answ[i][c[i][j]] == 0)
            return;
    res += 2;
}

void solve()
{
    memset(answ, 0, sizeof(answ));
    n = read(),
    m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            c[i][j] = read();
    for (int i = 1; i <= n; i++)
    {
        int tmpn = read();
        for (int j = 1; j <= tmpn; j++)
            answ[i][read()] = 1;
    }
    for (int i = 1; i <= n; i++)
        chuli(i);
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}