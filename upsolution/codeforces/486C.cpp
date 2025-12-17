#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

ll a;
const ll pax = 1e18 + 1;

void solve()
{
    cin >> a;
    ll l = a - pax % a * 9 % a * 9 % a, r = pax + l - 1;
    cout << l << ' ' << r << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}