#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;

ll k, res, x0, y00, n, m, dx, dy, x, y;
const ll p = 1e9 + 7;

void solve()
{
    cin >> n >> m >> k >> x0 >> y00;
    for (ll i = 1; i <= k; i++)
    {
        cin >> x >> y;
        if (x > x0)
            dx = n - x + 1;
        else
            dx = x;
        if (y > y00)
            dy = m - y + 1;
        else
            dy = y;
        if (x == x0)
        {
            dy %= p;
            res = (res + ll(dy * (ll(m + n - 3 + m - dy) % p))) % p;
        }
        else if (y == y00)
        {
            dx %= p;
            res = (res + ll(dx * (ll(m + n - 3 + n - dx) % p))) % p;
        }
        else
        {
            dy %= p, dx %= p;
            res = (res + dx + dy) % p;
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