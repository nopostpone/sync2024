// https://www.luogu.com.cn/problem/P8772
// 前缀和
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 100;

ll n, res;
ll a[N], pdx[N];

void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    pdx[n] = a[n];
    for (ll i = n - 1; i; i--)
        pdx[i] = a[i] + pdx[i + 1];
    for (ll i = 1; i <= n - 1; i++)
        res += a[i] * pdx[i + 1];
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