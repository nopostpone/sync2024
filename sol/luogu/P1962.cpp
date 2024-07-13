#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 1e5 + 100;

ll x;
ll c[N][N];

void multi(int a[][N], int b[][N], int n)
{
    int tmp[N][N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                tmp[i][j] += a[i][k] * b[k][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = tmp[i][j];
}

void fastpow(int a[][N],int n)
{
    
}

void solve()
{
    cin >> x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}