// https://www.luogu.com.cn/problem/P1048
//  01背包例题
//  其中状态方程可以降为一维
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1010;

int T, n;
int t[N], v[N];
int f[N][N];

void solve()
{
    cin >> T >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> v[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = T; j; j--)
        {
            if (j >= t[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - t[i]] + v[i]);
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][T];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}

// 数据加强版本：https://www.luogu.com.cn/problem/P2871
// 需要将状态方程数组降维

// int n, m;
// int t[N], v[N];
// int f[N];

// void solve()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> t[i] >> v[i];
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = m; j; j--)
//         {
//             if (j >= t[i])
//             {
//                 f[j] = max(f[j], f[j - t[i]] + v[i]);
//             }
//         }
//     }
//     cout << f[m];
// }