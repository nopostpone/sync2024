// https://www.luogu.com.cn/problem/P1331
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;
const int inf = 0x7fffffff;

int n,m;
bool mp[N][N];
int id[N][N];
int area[N*N];
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};

bool isin(int x,int y)
{
    if(x<1 or x>n or y<1 or y>m)
        return false;
    return true;
}

void bad()
{
    cout<<"Bad placement."<<endl;
    exit(0);
}

void bfs(int x0,int y0,int idx)
{
    queue<pair<int,int>> qe;
    qe.push({x0,y0});
    id[x0][y0]=idx;
    int minx=inf,miny=inf,maxx=-inf,maxy=-inf;
    while(!qe.empty())
    {
        area[idx]++;
        int x=qe.front().first, y=qe.front().second;
        minx=min(minx,x);
        miny=min(miny,y);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
        int nx,ny;
        for(int i=1;i<=4;i++)
        {
            nx=x+dx[i],ny=y+dy[i];
            if(isin(nx,ny) and mp[nx][ny] and id[nx][ny]==0)
            {
                qe.push({nx,ny}),id[nx][ny]=idx;
            }
        }
        qe.pop();
    }
    if((maxx-minx+1)*(maxy-miny+1)!=area[idx])
        bad();
}

void solve()
{
    char ch;
    int num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>ch;
            if(ch=='.')mp[i][j]=0;
            else if(ch=='#')mp[i][j]=1;
            else
            {
                cout<<"error"<<endl;
                exit(0);
            }
        }
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++)
    //         cout<<mp[i][j]<<" \n"[j==m];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(id[i][j]==0 and mp[i][j])
                bfs(i,j,++num);
    cout<<"There are "<<num<<" ships.";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}