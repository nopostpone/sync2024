// https://www.luogu.com.cn/problem/P5318
// bfs&dfs 模板题
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define qwq (cout << "qwq" << endl)
using ll = long long;
const ll inf = 0x3f3f3f3f;
const int N = 1e5 + 7;

struct edge
{
    int u, v;
    bool operator<(const edge &rhs) const
    {
        return u == rhs.u ? v < rhs.v : u < rhs.u;
    }
};
vector<edge> s;
vector<int> g[N];
bool vis[N];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void dfs(int st)
{
    // if (vis[st] == 1)
    //     return;
    vis[st] = 1;
    cout << st << ' ';
    for (int i = 0; i < g[st].size(); i++)
        if (!vis[s[g[st][i]].v])
            dfs(s[g[st][i]].v);
}

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    cout << st << ' ';
    vis[st] = 1;
    while (!q.empty())
    {
        int fr = q.front();
        for (int i = 0; i < g[fr].size(); i++)
        {
            int ed = s[g[fr][i]].v;
            if (!vis[ed])
            {
                q.push(ed);
                cout << ed << ' ';
                vis[ed] = 1;
            }
        }
        q.pop();
    }
}

void solve()
{
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
        s.push_back((edge){read(), read()});
    sort(s.begin(), s.end());
    for (int i = 0; i < m; i++)
        g[s[i].u].push_back(i);
    memset(vis, 0, sizeof(vis));
    dfs(1);
    memset(vis, 0, sizeof(vis));
    cout << endl;
    bfs(1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}