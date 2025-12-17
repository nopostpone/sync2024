// https://www.luogu.com.cn/problem/P1443
// 马的遍历 - bfs
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 500;
bool vis[N][N];
int res[N][N];
int sx, sy, n, m;

int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};

bool IsOut(int x, int y)
{
    return x > n || x < 1 || y > m || y < 1;
}

bool isin(int x, int y)
{
    return x > 0 and y > 0 and x <= n and y <= m;
}

void bfs(int x0, int y0)
{
    queue<pair<int, int>> qe;
    qe.push({x0, y0});
    res[x0][y0] = 0;
    vis[x0][y0] = 1;
    while (!qe.empty())
    {
        int x = qe.front().first, y = qe.front().second;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (isin(nx, ny) and !vis[nx][ny])
                res[nx][ny] = res[x][y] + 1,
                qe.push({nx, ny}),
                vis[nx][ny] = 1;
        }
        qe.pop();
    }
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> sx >> sy;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res[i][j] = -1;
    bfs(sx, sy);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << res[i][j] << " \n"[j == m];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}