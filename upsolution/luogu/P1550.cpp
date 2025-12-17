// https://www.luogu.com.cn/problem/P5461
// 最小生成树
// 原地打井 = 和第0个点相连
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 1e5 + 10;
int pre[N];
struct edge
{
    int u, v, w;
    bool operator<(const edge &o) const
    {
        return w < o.w;
    }
};
vector<edge> g;
ll res;

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void merge(int x, int y)
{
    pre[root(x)] = root(y);
}

bool iscon(int x, int y)
{
    return root(x) == root(y);
}

void solve()
{
    int n, m, k, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        g.push_back({i, 0, w});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            g.push_back({i, j, w});
        }
    }
    sort(g.begin(), g.end());
    for (int i = 0; i <= n; i++)
        pre[i] = i;
    for (auto i = g.begin(); i != g.end(); i++)
    {
        if (cnt == n)
            break;
        int u = i->u, v = i->v;
        if (iscon(u, v))
            continue;
        merge(u, v);
        res += i->w;
        cnt++;
    }
    if (cnt == n)
        cout << res << endl;
    else
        cout << "No Answer";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}