// https://www.luogu.com.cn/problem/P3366
// 最小生成树模板
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
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    sort(g.begin(), g.end());
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    for (auto i = g.begin(); i != g.end(); i++)
    {
        if (cnt == n - 1)
            break;
        int u = i->u, v = i->v;
        if (iscon(u, v))
            continue;
        merge(u, v);
        res += i->w;
        cnt++;
    }
    if (cnt == n - 1)
        cout << res;
    else
        cout << "orz";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}