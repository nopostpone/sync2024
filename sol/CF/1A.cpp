// https://codeforces.com/contest/1/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int res1, res2;
ll res;
void solve()
{
    int n, m, a;
    cin >> n >> m >> a;
    if (n % a)
        res1 = n / a + 1;
    else
        res1 = n / a;
    if (m % a)
        res2 = m / a + 1;
    else
        res2 = m / a;
    res = 1LL * res1 * res2;
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