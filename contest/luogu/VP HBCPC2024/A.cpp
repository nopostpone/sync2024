#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    ll x, y;
    cin >> x >> y;
    
    ll A = __gcd(x, y);
    ll res = 1LL * x / A * y / A;
    cout << 1 << " " << res << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}