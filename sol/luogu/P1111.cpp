// https://www.luogu.com.cn/problem/P1111
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 1e5 + 10;
int pre[N];
struct edge
{
    int u, v, t;
    bool operator<(const edge &o) const
    {
        return t < o.t;
    }
};
vector<edge> g;

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
    int n, m, tres, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        g.push_back({u, v, t});
    }
    sort(g.begin(), g.end());
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    for (auto i = g.begin(); i != g.end(); i++)
    {
        int u = i->u, v = i->v;
        if (iscon(u, v))
            continue;
        merge(u, v);
        tres = i->t;
        cnt++;
    }
    if (cnt == n - 1)
        cout << tres;
    else
        cout << -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}