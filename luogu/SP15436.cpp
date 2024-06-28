// https://www.spoj.com/problems/UCV2013H/
// https://www.luogu.com.cn/problem/SP15436
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;
const int M = 1e5 + 100;

bool mp[N][N];
int id[N][N];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int n, m;
vector<int> ve;
int t[62500];

bool isin(int x, int y)
{
    return x > 0 and y > 0 and x <= n and y <= m;
}

void bfs(int a, int b, int idx)
{
    int res = 0;
    queue<pair<int, int>> qe;
    qe.push({a, b});
    id[a][b] = idx;
    while (!qe.empty())
    {
        int x = qe.front().first, y = qe.front().second;
        int nx, ny;
        res++;
        for (int i = 1; i <= 4; i++)
        {
            nx = x + dx[i], ny = y + dy[i];
            if (mp[nx][ny] and id[nx][ny] == 0 and isin(nx, ny))
                qe.push({nx, ny}), id[nx][ny] = idx;
        }
        qe.pop();
    }
    t[res]++;
    ve.push_back(res);
}

void solve()
{
    cin >> n >> m;
    if (!m and !n)
        exit(0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mp[i][j];
    memset(id, 0, sizeof(id));
    memset(t, 0, sizeof(t));
    ve.clear();
    int num = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (id[i][j] == 0 and mp[i][j])
                bfs(i, j, ++num);
    cout << num << endl;
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    for (auto &i : ve)
        cout << i << ' ' << t[i] << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (1)
        solve();
    return 0;
}