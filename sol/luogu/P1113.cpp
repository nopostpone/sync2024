// https://www.luogu.com.cn/problem/P1113
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e4 + 100;

vector<int> g[N];
struct node
{
    int id, len;
    vector<int> pre;
    void addedge()
    {
        for (auto &to : pre)
        {
            g[to].push_back(id);
        }
    }
} a[N];
int n;
bool vis[N];
int res;

void dfs(int now, int time)
{
    if (g[now].empty())
    {
        res = max(time, res);
        return;
    }
    if (vis[now])
        return;
    vis[now] = 1;
    for (auto &to : g[now])
    {
        dfs(to, time + a[to].len);
    }
    vis[now] = 0;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int id;
        cin >> id;
        cin >> a[id].len;
        a[id].id = id;
        int p;
        cin >> p;
        while (p != 0)
        {
            a[id].pre.push_back(p);
            cin >> p;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i].addedge();
    }
    dfs(1, a[1].len);

    // queue<int> qu;
    // qu.push(1);
    // vis[1] = 1;
    // res += a[1].len;
    // while (!qu.empty())
    // {
    //     int now = qu.front();
    //     qu.pop();
    //     priority_queue<int, vector<int>, less<int>> pq;
    //     for (auto &to : g[now])
    //     {
    //         if (vis[to])
    //             continue;
    //         pq.push(a[to].len);
    //         vis[to] = 1;
    //         qu.push(to);
    //     }
    //     if (!pq.empty())
    //         res += pq.top();
    // }


    cout << res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}