#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    double m;
    cin >> n >> m;

    const ll p = 1. * m * 1e10;

    ll s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }

    int res = -1;
    for (ll i = 1; i <= n; i++) {
        if (1ll * i * 1e12 >= p * s) {
            res = i;
            break;
        }
    }
    cout << res << endl;
    
    return 0;
}