#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 300 + 4;
const int inf = 0x3f3f3f3f;

int n, m;
int v[N], p[N];
ll f[N][N][N];
int vmin, vsum;
int cnt;

// f[i][j][k] 表示考虑前 i 件物品，背包容量为 j，选取 k 件物品时最高的收益。

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> p[i];
    }
    vmin = *min_element(v + 1, v + n + 1) - 1;

    for (int i = 1; i <= n; i++)
    {
        v[i] -= vmin;
        vsum += v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j{0}; j <= vsum; j++)
        {
            for (int k{1}; k <= n; k++)
            {
                if (1LL * k * vmin + j <= m and j >= v[i])
                {
                    f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - v[i]][k - 1] + p[i]);
                }
                else
                {
                    f[i][j][k] = f[i - 1][j][k];
                }
            }
        }
    }
    ll res = 0;
    for (int j{0}; j <= vsum; j++)
    {
        for (int k{1}; k <= n; k++)
        {
            res = max(res, f[n][j][k]);
        }
    }

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