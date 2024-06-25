#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

int res,n,st0,ed0;
int g[N];
bool vis[N];
bool isar=0;

void dfs(int fa,int lvl)
{
    if(fa==ed0){res=min(res,lvl);isar=1;return;}
    vis[fa]=true;
    for(int i=-1;i<=1;i+=2)
    {
        int son = fa+i*g[fa];
        if(son>0 and son<=n and !vis[son])
            dfs(son,lvl+1);
    }
    vis[fa]=false;
}

void bfs()
{
    queue<pair<int,int>>qe;
    qe.push({st0,0});
    vis[st0]=true;
    while(!qe.empty())
    {
        int lvl=qe.front().first;
        int ans=qe.front().second;
        for(int i=-1;i<=1;i+=2)
        {
            int nlvl=lvl+i*g[lvl];
            if(nlvl==ed0)
            {
                isar=1;
                res=min(res,ans+1);
                break;
            }
            if(nlvl>0 and nlvl<=n and !vis[nlvl])
                qe.push({nlvl,ans+1}),vis[nlvl]=true;
        }
        qe.pop();
    }
}

void solve()
{
    res=0x7fffffff;
    cin>>n>>st0>>ed0;
    if(st0==ed0)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
        cin>>g[i];
    bfs();
    if(isar)
    cout<<res<<endl;
    else cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}