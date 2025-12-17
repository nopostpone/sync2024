#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int a[N];

void solve()
{
    int n, jicnt = 0, oucnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] & 1)
            jicnt++;
        else
            oucnt++;
    }
    while (oucnt > 0 and jicnt > 0)
    {
        oucnt--, jicnt--;
    }
    if (jicnt & 1)
        jicnt = 1;
    else
        jicnt = 0;
    cout << oucnt + jicnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}