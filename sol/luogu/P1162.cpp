#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 100;

int mp[N][N];
bool vis[N][N];
int n;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isin(int x, int y)
{
    return x <= n and y <= n and x > 0 and y > 0;
}

void bfs(int x0, int y0)
{
    queue<pair<int, int>> qe;
    qe.push({x0, y0});
    mp[x0][y0] = -1;
    while (!qe.empty())
    {
        int x = qe.front().first, y = qe.front().second;
        int nx, ny;
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i], ny = y + dy[i];
            if (!mp[nx][ny] and isin(nx, ny))
                mp[nx][ny] = -1,
                qe.push({nx, ny});
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++)
    {
        if (!mp[i][1])
            bfs(i, 1);
        if (!mp[1][i])
            bfs(1, i);
        if (!mp[i][n])
            bfs(i, n);
        if (!mp[n][i])
            bfs(n, i);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mp[i][j] == -1)
                mp[i][j] = 0;
            else if (mp[i][j] == 0)
                mp[i][j] = 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << mp[i][j] << " \n"[j == n];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}