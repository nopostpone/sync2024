// B3944
// https://www.luogu.com.cn/problem/B3944
// A simple maintaining method
// Maintain the data with modulo in every cycle
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const ll inf = pow(2, 31) - 1;
const int N = 1e6 + 100;

ll ans = 1;
ll a;
const int p = 722733748;

void solve()
{
    int k, q;
    cin >> k >> a >> q;
    for (int i = 1; i <= k; i++)
    {
        ans = (ans * a) % p;
        a = (a * q) % p;
    }
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
