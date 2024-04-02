// B3949
// 给定10^n的范围，找数位和不大于k的数有多少
// 初见的时候思路太混沌了，越急越做不出来= =
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const ll inf = pow(2, 31) - 1;
const int N = 1e6 + 100;

int f(int x)
{
    int tmp = x;
    int sum = 0;
    while (tmp)
        sum += (tmp % 10), tmp /= 10;
    return sum;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int a = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        a *= 10;
    for (int i = 1; i < a; i++)
        if (f(i) <= k)
            ans++;
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}