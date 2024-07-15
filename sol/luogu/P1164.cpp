#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 3;

int a[N];
int n, m;
int f[N][N];

// 记f[i][j]为考虑前i道菜，有m快钱时的方案数量
// 如果j == a[i]，那么f[i][j] = f[i-1][j] + 1
// 如果j > a[i]，f[i][j] = f[i-1][j-a[i]] + f[i-1][j]

void solve()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j < a[i])
                f[i][j] = f[i - 1][j];
            else if (j > a[i])
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
            else
                f[i][j] = f[i - 1][j] + 1;
        }
    }
    cout << f[n][m];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}