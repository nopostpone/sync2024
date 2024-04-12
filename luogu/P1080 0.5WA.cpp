// P1080
// 国王游戏
// 从相邻两项交换前后的不同 推导贪心的条件
// 还要用高精度，很麻烦，这里没写
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define space << "  " <<
using ll = long long;
const ll inf = pow(2, 31) - 1;
const int N = 1e6 + 100;

string res;

struct ren
{
    int l, r;
    string money;
    bool operator<(const ren &rhs) const
    {
        return max(rhs.r, l * r) < max(r, rhs.l * rhs.r);
    }
} a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + 1 + n);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}