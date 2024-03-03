#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505;
int a[N][N], temp[N][N];
struct que
{
    int x, y, r;
    bool z;
} q[N];

int n, m;

void copy()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            temp[i][j] = a[i][j];
}

void shun(int x, int y, int r)
{
    int i, j;
    for (i = x - r; i <= x + r; i++)
        for (j = y - r; j <= y + r; j++)
            a[i][j] = temp[x + y - j][y + i - x];
}

void ni(int x, int y, int r)
{
    int i, j;
    for (i = x - r; i <= x + r; i++)
        for (j = y - r; j <= y + r; j++)
            a[x + y - j][y + i - x] = temp[i][j];
}

void solve()
{
    cin >> n >> m;
    int i, j, k;
    for (i = 1; i <= m; i++)
        cin >> q[i].x >> q[i].y >> q[i].r >> q[i].z;
    k = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = k++;

    for (i = 1; i <= m; i++)
    {
        copy();
        if (q[i].z == 0)
            shun(q[i].x, q[i].y, q[i].r);
        else
            ni(q[i].x, q[i].y, q[i].r);
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}