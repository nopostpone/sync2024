// https://www.luogu.com.cn/problem/P1596
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e3 + 100;

int n,m;
bool mp[N][N];
int id[N][N];
int dx[9]={0,1,-1,0,0,1,1,-1,-1};
int dy[9]={0,0,0,1,-1,1,-1,1,-1};

bool isin(int x,int y)
{
    if(x<1 or x>n or y<1 or y>m)
        return false;
    return true;
}

void bfs(int x0,int y0,int idx)
{
    queue<pair<int,int>> qe;
    qe.push({x0,y0});
    id[x0][y0]=idx;
    while (!qe.empty())
    {
        int x=qe.front().first,y=qe.front().second;
        int nx,ny;
        for(int i=1;i<=8;i++)
        {
            nx=x+dx[i],ny=y+dy[i];
            if(isin(nx,ny) and id[nx][ny]==0 and mp[nx][ny])
            {
                qe.push({nx,ny}),id[nx][ny]=idx;
            }
        }
        qe.pop();
    }
}

void solve()
{
    char ch;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>ch;
            if(ch=='W')
                mp[i][j]=1;
            else if (ch=='.')
                mp[i][j]=0;
            else
            {
                cout<<"err"<<endl;
                exit(0);
            }
        }
    int num=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j] and id[i][j]==0)
                bfs(i,j,++num);
    
    cout<<num;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}