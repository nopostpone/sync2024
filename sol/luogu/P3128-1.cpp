// https://www.luogu.com.cn/problem/P3128
// 树剖+差分 O(nlogn)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define lst pos << 1
#define rst pos << 1 | 1
const int N = 1e5 + 10;

int n,m;
vector<int> g[N];
int dep[N], dfn[N], top[N], pre[N], a[N];

void dfs1(int now, int fa)
{

}

void dfs2(int now, int tp)
{

}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
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