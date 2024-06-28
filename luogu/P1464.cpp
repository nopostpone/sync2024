#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

struct node
{
    ll x, y, z, res = 0;

    int pf()
    {
        cout << "w(" << x << ", " << y << ", " << z << ") = " << res;
    }
} a[N];

int w(int x, int y, int z)
{
    if (x <= 0 or y <= 0 or z <= 0)
        return 1;
    if (x > 20 or y > 20 or z > 20)
        return w(20, 20, 20);
}

int w(node &A)
{
    return w(A.x, A.y, A.z);
}

void solve()
{
    ll aa, bb, cc;
    int m = 0;
    while (cin >> aa >> bb >> cc)
    {
        if (aa == -1 and bb == -1 and cc == -1)
            return;
        a[++m] = {aa, bb, cc, 0};
    }
    for (int i = 1; i <= m; i++)
        a[i].res = w(a[i]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}