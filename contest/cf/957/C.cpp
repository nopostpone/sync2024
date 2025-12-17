#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 10;

int n, m, k;
int a[N];

void solve()
{
    cin >> n >> m >> k;
    for (int i = n; i >= k; i--)
    {
        cout << i << ' ';
    }
    for (int i = m + 1; i < k; i++)
    {
        cout << i << ' ';
    }
    for (int i = 1; i <= m; i++)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}