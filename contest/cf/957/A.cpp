#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int a[10];

void solve()
{
    int t = 5;
    cin >> a[1] >> a[2] >> a[3];
    while (t--)
    {
        sort(a + 1, a + 4);
        a[1]++;
    }
    int res = a[1] * a[2] * a[3];
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}