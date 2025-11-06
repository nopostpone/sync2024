// P1080
// https://www.luogu.com.cn/problem/P1080
// 国王游戏
// 从相邻两项交换前后的不同 推导贪心的条件
// 题目给的数据很大，需要用高精度，这里没有用，所以只能拿一半的分
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define space << "  " <<
using ll = long long;
const ll inf = pow(2, 31) - 1;
const int N = 1e6 + 100;

struct ren
{
    int l, r;
    double m = 0;
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
    a[1].m = (double)a[0].l / a[1].r;
    for (int i = 2; i <= n; i++)
        a[i].m = (a[i - 1].m) * a[i - 1].r * a[i - 1].l / (double)(a[i].r);
    // for (int i = 0; i <= n; i++)
    //     cout << i space a[i].m << endl;
    double res;
    for (int i = 1; i <= n; i++)
        res = max(a[i - 1].m, a[i].m);
    cout << ll(res);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}