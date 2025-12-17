#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e5 + 100;

ll a[N];
vector<ll> res;
int n, xx;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> xx;
    for (int i = 1; i <= n; i++)
    {
    }
    for (auto &i : res)
        cout << i << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _=1;
    while (_--)
        solve();
    return 0;
}