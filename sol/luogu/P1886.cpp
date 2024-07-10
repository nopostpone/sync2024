// https://www.luogu.com.cn/problem/P1886
// 单调队列
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define enter putchar('\n')
const int N = 3e6 + 3;

ll n, k;
ll a[N];
deque<ll> da, xiao;
vector<vector<ll>> res;

void solve()
{
    cin >> n >> k;
    vector<ll> tmp(n);
    res.resize(2, tmp);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (!da.empty() and a[i] >= a[da.back()])
            da.pop_back();
        while (!xiao.empty() and a[i] <= a[xiao.back()])
            xiao.pop_back();
        da.push_back(i);
        xiao.push_back(i);
        while (i - k >= da.front())
            da.pop_front();
        while (i - k >= xiao.front())
            xiao.pop_front();
        if (i >= k)
        {
            res[0][i - k] = a[da.front()];
            res[1][i - k] = a[xiao.front()];
        }
    }
    for (int i : {1, 0})
        for (int j = 0; j < n - k + 1; j++)
            cout << res[i][j] << " \n"[j == n - k];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}