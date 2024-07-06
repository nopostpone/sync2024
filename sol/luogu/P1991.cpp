// https://www.luogu.com.cn/problem/P1991
// 瓶颈生成树
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 1e5 + 10;
int pre[N];
struct edge
{
    int u, v;
    double w;
    bool operator<(const edge &o) const
    {
        return w < o.w;
    }
};
struct node
{
    int x, y;
} a[N];

vector<edge> g;
double res;

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
    int n, m, ss, cnt = 0;
    cin >> ss >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double dis;
            dis = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
            g.push_back({i, j, dis});
            g.push_back({j, i, dis});
        }
    }
    sort(g.begin(), g.end());
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    for (auto i = g.begin(); i != g.end(); i++)
    {
        if (cnt == n - ss)
        {
            break;
        }
        int u = i->u, v = i->v;
        if (iscon(u, v))
            continue;
        merge(u, v);
        res = max(res, i->w);
        // cout << u << ' ' << v << ' ' << i->w << endl;
        cnt++;
    }
    cout << fixed << setprecision(2) << res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}