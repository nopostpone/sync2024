// https://www.luogu.com.cn/problem/P2742
// 二维凸包
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;
const double eps=1e-12;

struct point
{
    double x,y;
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
    }
    inline point operator-(const point &o)const{return point{x-o.x,y-o.y};}
    inline point operator+(const point &o)const{return point{x+o.x,y+o.y};}
    inline double operator^(const point &o)const{return x*o.x+y*o.y;}
    inline double operator*(const point &o)const{return x*o.y-y*o.x;}
    inline double getlen(){return sqrt(x*x+y*y);}
}pt[N];

struct line
{
    int p[2];
    point Normal()
    {
        point o=pt[p[1]]-pt[p[0]];
        return point{-1./o.x,1./o.y};
    }
    bool IsRight(const point &o)
    {
        return (Normal ^ o) >= 0;
    }
    double getlen()
    {
        point o=pt[p[1]]-pt[p[0]];
        return o.getlen();
    }
}l[N],t[N];

int n,m;

void solve()
{
    
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}