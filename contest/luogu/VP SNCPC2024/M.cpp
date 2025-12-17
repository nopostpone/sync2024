#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e4 + 100;

bool vis[210][210];

double res;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        x = 2 * x, y = 2 * y;
        vis[x][y] = 1;
        vis[x + 1][y + 1] = 1;
        vis[x][y + 2] = 1;
        vis[x - 1][y + 1] = 1;
    }
    for (int y = 1; y <= 201; y += 2)
    {
        for (int x = 1; x <= 199; x += 2)
        {
            if (vis[x][y])
            {
                if (y == 1 or y == 201)
                    res += 0.25;
                else
                    res += 0.5;
            }
        }
    }
    for (int y = 2; y <= 200; y += 2)
    {
        for (int x = 0; x <= 200; x += 2)
        {
            if (vis[x][y])
            {
                if (x == 0 or x == 200)
                    res += 0.25;
                else
                    res += 0.5;
            }
        }
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}