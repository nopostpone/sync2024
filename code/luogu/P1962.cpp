// https://www.luogu.com.cn/problem/P1962
// 斐波那契数列 矩阵快速幂 O(logN)
// fn   =   fn-1 + fn-2     =   1 1 *   fn-1
// fn-1     fn-1 + 0*fn-2       1 0     fn-2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

ll x;
const ll p = 1e9 + 7;

struct matrix
{
    ll a[3][3];
    void init()
    {
        memset(a, 0, sizeof(a));
        for (int i : {1, 2})
            a[i][i] = 1;
    }
    void base()
    {
        a[1][1] = 1;
        a[1][2] = 1;
        a[2][1] = 1;
        a[2][2] = 0;
    }
};

void deb(matrix &x)
{
    for (int i : {1, 2})
        for (int j : {1, 2})
        {
            cout << x.a[i][j] << " \n"[j == 2];
        }
}

matrix mul(matrix A, matrix B)
{
    matrix ans;
    for (int i : {1, 2})
    {
        for (int j : {1, 2})
        {
            ans.a[i][j] = 0;
            for (int k : {1, 2})
            {
                ans.a[i][j] %= p;
                ans.a[i][j] += A.a[i][k] * B.a[k][j] % p;
            }
        }
    }
    return ans;
}

matrix fastpow(matrix A, ll b)
{
    matrix ans;
    ans.init();
    while (b)
    {
        if (b & 1)
        {
            ans = mul(ans, A);
        }
        A = mul(A, A);
        b >>= 1;
    }
    return ans;
}

void solve()
{
    cin >> x;
    matrix base;
    base.base();
    matrix ans;
    ans.a[1][1] = 1;
    ans.a[1][2] = 0;
    ans = mul(ans, fastpow(base, x - 1));
    cout << ans.a[1][1] % p << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}