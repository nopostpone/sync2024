#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e7 + 100;

int n;
double k;
double a[N], b[N];
ll c[N];

void f(int x)
{
    c[x] = x * c[x - 1];
}

void solve()
{
    int t;
    cin >> t;
    c[0] = 1;
    for (int i = 1; i <= 18; i++)
    {
        c[i] = 1;
        f(i);
    }
    for (int i = 1; i <= 18; i++)
    {
    }
    // while (t--)
    // {
    //     cin >> n >> k;
    //     cout << fixed << setprecision(1) << f(n) << endl;
    // }
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}