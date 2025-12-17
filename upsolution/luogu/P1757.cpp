// https://www.luogu.com.cn/problem/P1757
// 分组背包
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const int N = 1e3 + 10;
ll w[N], v[N], cnt[N];
ll t[N][N];
ll f[N];

void solve()
{
    int x = 0;
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        t[c][++cnt[c]] = i;
        w[i] = a;
        v[i] = b;
        x = max(x, c);
    }
    for (int k = 1; k <= x; k++)
    {
        for (int i = m; i; i--)
        {
            for (int j = 1; j <= cnt[k]; j++)
            {
                ll we = w[t[k][j]], val = v[t[k][j]];
                if (j >= we)
                {
                    f[i] = max(f[i], f[i - we] + val);
                }
            }
        }
    }
    cout << f[m];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}