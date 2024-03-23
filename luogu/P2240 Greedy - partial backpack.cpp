#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const ll inf = pow(2, 31) - 1;
const int N = 1e2 + 100;

struct coin
{
    double m, v, vm;
    bool operator<(const coin &rhs) const
    {
        return vm > rhs.vm;
    }
} a[N];

void solve()
{
    int n, t;
    double res = 0;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i].m >> a[i].v;
    for (int i = 1; i <= n; i++)
        a[i].vm = a[i].v / a[i].m;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (t < a[i].m)
        {
            double bl = (double)t / a[i].m;
            res += bl * a[i].v;
            break;
        }
        res += a[i].v;
        t -= a[i].m;
    }
    printf("%.2f", res);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}