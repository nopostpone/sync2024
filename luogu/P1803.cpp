// P1803
// 线段覆盖
// 还没弄清楚这么做为什么是最优的，有空了再看看
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const ll inf = pow(2, 31) - 1;
const int N = 1e6 + 100;

struct jingsai
{
    int l, r;
    bool operator<(const jingsai &rhs) const
    {
        return r <= rhs.r;
    }
} a[N];

void solve()
{
    int n;
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1);
    int st = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << a[i].l << "  " << a[i].r << "  " << a[i].t << endl;
        if (st > a[i].l)
            continue;
        st = a[i].r;
        res++;
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}