#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e4 + 3;

int a[N], t[N];
int n, m;
int f[N];

void solve()
{
    cin >> m >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> t[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = t[i]; j <= m; j++)
        {
            f[j] = max(f[j - t[i]] + a[i], f[j]);
        }
    }
    cout << f[m];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}