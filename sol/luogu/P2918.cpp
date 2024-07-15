#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 6e4 + 4;
const int inf = 0x3f3f3f3f;

int v[N], w[N];
int n, m;
int f[N];

// f[i] 表示买质量i的草花的最少钱数
// 需要质量 m 的干草，买到的干草可能在 [m, m+5000] 这个区间（w[i]<=5000）
// 所以 [f[m], f[m+5000]] 中的最小值即为所求

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(f, inf, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = w[i]; j <= m + 5000; j++)
        {
            f[j] = min(f[j], f[j - w[i]] + v[i]);
        }
        // for (int i = 1; i <= m; i++)
        //     cout << i << ' ' << f[i] << endl;
        // cout << endl;
    }
    cout << *min_element(f + m, f + m + 5000);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}