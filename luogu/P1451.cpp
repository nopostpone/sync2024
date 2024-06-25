// https://www.luogu.com.cn/problem/P1451
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e2 + 100;

int n, m;
bool mp[N][N];
int id[N][N];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

bool isout(int x, int y)
{
    if (x < 1 or y < 1 or x > n or y > m)
        return true;
    return false;
}

void bfs(int a, int b, const int idx)
{
    queue<pair<int, int>> qe;
    id[a][b] = idx;
    qe.push({a, b});
    while (!qe.empty())
    {
        int x = qe.front().first, y = qe.front().second;
        int nx, ny;
        for (int i = 1; i <= 4; i++)
        {
            nx = x + dx[i], ny = y + dy[i];
            if (!isout(nx, ny) and mp[nx][ny] and id[nx][ny] == 0)
                qe.push({nx, ny}), id[nx][ny] = idx;
        }
        qe.pop();
    }
}

void solve()
{
    memset(id,0,sizeof(id));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = (ch ^ 48) == 0 ? 0 : 1;
        }
    int idx = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] and id[i][j] == 0)
                bfs(i, j, idx++);
    cout<<idx-1<<endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}