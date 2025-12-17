#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

bool vis[21][21][21];
ll f[21][21][21];

ll w(ll x, ll y, ll z)
{
    if (x <= 0 or y <= 0 or z <= 0)
        return 1;
    else if (x > 20 or y > 20 or z > 20)
    {
        return w(20, 20, 20);
    }
    if (vis[x][y][z])
        return f[x][y][z];
    if (x < y and y < z)
    {
        vis[x][y][z] = 1;
        f[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) + w(x, y - 1, z);
    }
    vis[x][y][z] = 1;
    f[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
    return f[x][y][z];
}
struct node
{
    ll x, y, z;
    void pf()
    {
        cout << "w(" << x << ", " << y << ", " << z << ") = " << w(x, y, z) << endl;
    }
} a[N];

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
            break;
        a[++m] = node{aa, bb, cc};
    }
    for (int i = 1; i <= m; i++)
        a[i].pf();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}