// luogu P10056 240209
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, n;
    cin >> a >> b >> n;
    ll b0 = b;
    ll n0 = n;
    for (;;)
    {
        if (n == 1)
            break;
        if (b + b0 > a)
            break;
        --n;
        b += b0;
    }
    cout << b << '\n';
    return 0;
}