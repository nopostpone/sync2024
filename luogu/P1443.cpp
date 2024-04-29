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

struct point
{
    int x, y;
};

int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};

bool IsOut(int x, int y)
{
    return x > n || x < 1 || y > m || y < 1;
}

void bfs(int x, int y)
{
    queue<point> q;
    q.push({x, y});
    vis[x][y] = 1;
    res[x][y] = 0;
    while (!q.empty())
    {
        // cout << "st  " << q.front().x << ' ' << q.front().y << endl;
        for (int i = 0; i < 8; i++)
        {
            int nx = q.front().x + dx[i], ny = q.front().y + dy[i];
            if (IsOut(nx, ny) || vis[nx][ny] || (res[nx][ny] < res[q.front().x][q.front().y] + 1 && res[nx][ny] != -1))
                continue;
            // cout << i << ' ' << nx << ' ' << ny << endl;
            res[nx][ny] = res[q.front().x][q.front().y] + 1;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
        q.pop();
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