#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 100;

ll g[N];
ll res;

void solve()
{
    res = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    cout << *max_element(g + 1, g + 1 + n) << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}