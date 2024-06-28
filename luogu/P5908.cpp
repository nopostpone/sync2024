// https://www.luogu.com.cn/problem/P5908
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int n,dep[N];

vector<int>g[N];

void dfs(int now,int fa)
{
    dep[now]=dep[fa]+1;
    for(auto &i:g[now])
    {
        if(i==fa)
            continue;
        dfs(i,now);
    }
}

void solve()
{
    int d,res=-1;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dep[0]=-1;
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(dep[i]<=d)res++;
    }
    cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}