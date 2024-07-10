// https://www.luogu.com.cn/problem/P1776
// 多重背包 二进制优化
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 1e5 + 10;

int n, W;
int v[N], w[N], m[N];
int f[N], g[N];
int cnt;

void solve()
{
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        int wi, vi, mi;
        cin >> vi >> wi >> mi;
        for (int i = 1; i <= mi;)
        {
            w[++cnt] = i * wi;
            v[cnt] = i * vi;
            mi -= i;
            i *= 2;
        }
        if (mi > 0)
        {
            w[++cnt] = wi * mi;
            v[cnt] = vi * mi;
        }
    }
    n = cnt;
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    cout << f[W] << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}