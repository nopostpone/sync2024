// https://www.luogu.com.cn/problem/P1892
// diren の diren は pengyou です
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

const int N = 1e5 + 10;
int pre[N];

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void merge(int x, int y)
{
    pre[root(x)] = root(y);
}

bool iscon(int x, int y)
{
    return root(x) == root(y);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++)
        pre[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        char opt;
        cin >> opt >> x >> y;
        if (opt == 'F')
            merge(x, y);
        else if (opt == 'E')
            merge(y + n, x), merge(x + n, y);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        if (pre[i] == i)
            res++;
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}