#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int res = 0;
    if (n < k)
        res = n;
    else
        res = k;
    if (m < k)
        res *= m;
    else
        res *= k;
    
    cout << res << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}