#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;

int n, m;
bool mp[N][N], des[N][N];
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};

void ran(int x, int y)
{
    for (int i = 1; i <= 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        mp[nx][ny] = 1;
    }
}

bool isout(int x, int y)
{
    return x < 1 or y < 1 or x > n or y > m;
}

void solve()
{
    char ch;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if (ch == '#')
                des[i][j] = 1;
            else if (ch == '.')
                des[i][j] = 0;
            else
            {
                cout << "error" << endl;
                exit(0);
            }
        }
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++)
        {
            int nx, ny;
            bool flag = 1;
            for (int i = 1; i <= 8; i++)
            {
                nx = x + dx[i], ny = y + dy[i];
                if (isout(nx, ny) or !des[nx][ny])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ran(x, y);
        }
    bool ist = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] ^ des[i][j])
            {
                ist = 0;
                break;
            }
    if (ist)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}