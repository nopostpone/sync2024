#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int a[N];
int n, k;

void solve()
{
    ll cnt = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + k + 1);
    for (int i = 1; i < k; i++)
    {
        cnt += a[i] - 1;
    }
    cnt += n - a[k];
    cout << cnt << endl;
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