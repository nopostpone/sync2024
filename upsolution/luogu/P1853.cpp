#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e6 + 3;

int v[N], w[N];
int n, m, d, s;
int f[N];

void solve()
{
    cin >> s >> n >> d;
    for (int i = 1; i <= d; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++)
    {
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= d; j++)
        {
            for (int k = w[j] / 1000; k <= s / 1000; k++)
            {
                f[k] = max(f[k], f[k - w[j] / 1000] + v[j]);
            }
        }
        s += f[s / 1000];
    }
    cout << s;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}