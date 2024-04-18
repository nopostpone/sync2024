// B3947
// https://www.luogu.com.cn/problem/B3947
// 这题完全不会做，感觉像是动态规划
// 但其实不是，就是一个贪心，因为我看错题目了，真是节目效果拉满
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050;

ll ans = 0;
ll a[N][N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (ll i = 1; i <= n; i++)
    {
        ll tmp = -pow(2, 31) + 1;
        for (ll j = 1; j <= m; j++)
            tmp = max(tmp, (a[i][j] - j * k));
        ans += tmp;
    }

    cout << ans;
    return 0;
}