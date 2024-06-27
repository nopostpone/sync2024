// https://www.luogu.com.cn/problem/P4724
// 三维凸包
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 2e3+10;
const double eps = 1e-12;

struct point
{
    double x,y,z;
    inline double Rand(){return ((double)rand()/RAND_MAX);}
    inline double RandEps()
    {
        double RAND=Rand();
        return (RAND-0.5)*eps;
    }
    inline void Shake()
    {
        x+=RandEps();
        y+=RandEps();
        z+=RandEps();
    }
    inline point operator+(const point &o) const {return point{x+o.x,y+o.y,z+o.z};}
    inline point operator-(const point &o) const {return point{x-o.x,y-o.y,z-o.z};}
    inline double operator^(const point &o) const {return x*o.x+y*o.y+z*o.z;}
    inline point operator*(const point &o) const {return point{y*o.z-z*o.y,z*o.x-x*o.z, x*o.y-y*o.x};}
    inline double getlen()
    {
        return sqrt(x*x+y*y+z*z);
    }
};

vector<point>pt;

struct face
{
    int p[3];
    inline point Normal(){return (pt[p[1]]-pt[p[0]])*(pt[p[2]]-pt[p[1]]);}
    inline bool IsAbove(const point &o){return (Normal()^(o-pt[p[0]]))>=0;}
    inline double Area(){return Normal().getlen()*0.5;}
};

face sta[100000],fc[100000];
int n,m,cnt;
bool vis[N][N];

void db()
{
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    std::cout<<vis[i][j]<<" \n"[j==n-1];
}

void solve()
{   
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double x,y,z;
        cin>>x>>y>>z;
        pt.push_back(point{x,y,z});
    }
    for(auto i=pt.begin();i!=pt.end();i++)i->Shake();
    fc[m++]=face{0,1,2};
    fc[m++]=face{2,1,0};
    for(int i=3;i<n;i++)
    {
        cnt=0;
        for(int j=0;j<m;j++)
        {
            bool light = fc[j].IsAbove(pt[i]);
            if(!light)sta[cnt++]=fc[j];
            for(int k=0;k<3;k++)
            {
                int now=fc[j].p[k];
                int nxt=fc[j].p[(k+1)%3];
                vis[now][nxt]=light;
            }
        }
        for(int j=0;j<m;j++)
            for(int k=0;k<3;k++)
            {   
                int now=fc[j].p[k];
                int nxt=fc[j].p[(k+1)%3];
                if(vis[now][nxt] and !vis[nxt][now])
                    sta[cnt++]={now,nxt,i};
            }
        m=cnt;
        for(int j=0;j<m;j++)fc[j]=sta[j];
    }
    double res=0;
    for(int i=0;i<m;i++)
        res+=fc[i].Area();
    printf("%.3lf",res);
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}