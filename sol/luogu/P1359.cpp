#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 250;

int n;
int r[N][N], f[N][N];

int dp()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + min(r[i][j], r[i + 1][j]);
        }
    }
    return f[1][n];
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> r[i][j];
    cout << dp() << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}