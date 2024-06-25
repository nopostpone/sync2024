#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;
const int M = 1e5+100;

bool mp[N][N];
ll ans[N][N];
int id[N][N];
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
bool vis[N][N];
int n,m;
pair<int,int>query[M];

void pfdb(int swt)
{
    if(swt==1)
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<mp[i][j]<<" \n"[j==n];
    else if(swt==2)
    ;
}

bool isout(int x,int y)
{
    if(x<1 or x>n or y<1 or y>n)
    return true;
    return false;
}

void bfs(int a,int b)
{
    memset(vis,0,sizeof(vis));
    ll res=0;
    queue<pair<int,int>> qe;
    qe.push({a,b});
    vis[a][b]=true;
    while(!qe.empty())
    {
        int x=qe.front().first,y=qe.front().second;
        // cout<<"rudui "<<x<<' '<<y<<endl;
        int nx,ny;
        res++;
        for(int i=1;i<=4;i++)
        {
            nx=x+dx[i],ny=y+dy[i];
            if(mp[nx][ny]^mp[x][y] and !vis[nx][ny] and !isout(nx,ny))
                qe.push({nx,ny}),vis[nx][ny]=true;
        }
        qe.pop();
    }
    cout<<res<<endl;
}

void solve()
{
    memset(mp,0,sizeof(mp));
    cin>>n>>m;
    char cx;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>cx;
            if(cx=='1')
            mp[i][j] = true;
            else if (cx=='0')
            mp[i][j] = false;
            else exit(0);
        }
    // pfdb(1);
    for(int i=1;i<=m;i++)
        cin>>query[i].first>>query[i].second;
    for(int i=1;i<=m;i++)
        bfs(query[i].first,query[i].second);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}