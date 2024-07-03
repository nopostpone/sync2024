// https://www.luogu.com.cn/problem/P1359
// 置f[i][j]为考虑前i条船的情况下，到j出租站最少的花费
// 在每一个出租站，可以换船或者跳过
// 例如在(j-1)站——
// 跳过：f[i][j] = f[i-1][j]
// 换船（换要从i开始换）：f[i][j] = f[i-1][i]+r[i][j]
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 250;

int n;
int r[N][N], f[N][N];

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> r[i][j];
    for (int i = 2; i <= n; i++)
    {
        f[1][i] = r[1][i];
    }
    for (int i = 2; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i - 1][i] + r[i][j]);
        }
    cout << f[n - 1][n];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}