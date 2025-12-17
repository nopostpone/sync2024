#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 1e6 + 10;
int pre[N];
int a[N];
struct edge
{
    int u, v;
    ll w;
    bool use;
    bool operator<(const edge &o) const
    {
        return w < o.w;
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

vector<pair<int, int>> b;
ll ans;

void solve()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            g.push_back(edge{i, j, 1LL*a[i]*a[j], 0});
        }
    }
    std::sort(g.begin(), g.end());
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    for (auto i = g.begin(); i != g.end(); i++)
    {
        int u = i->u, v = i->v;
        if (iscon(u, v))
            continue;
        merge(u, v);
        b.push_back({u, v});
        ans += i->w;
        i->use = 1;
        cnt++;
    }
    for (auto i = g.begin(); i != g.end(); i++)
    {
        if (cnt == m)
            break;
        if (i->use)
            continue;
        i->use = 1;
        ans += i->w;
        b.push_back({i->u, i->v});
        cnt++;
    }

    cout << ans << endl;
    sort(b.begin(), b.end());
    for (auto &&[u, v] : b)
    {
        cout << u << ' ' << v << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}