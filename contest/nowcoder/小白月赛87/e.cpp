#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll bmin = 4e18, bmax = -4e18, t = -4e18;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        ll x = 0;
        if (a[i] > t) {
            t = a[i];
        } else {
            x = t - a[i];
        }
        bmax = max(bmax, x);
        bmin = min(bmin, x);
        b[i] = t;
    }    
    ll d = 0;
    if (bmax > 1e10) {
        d = bmax - 1e10;
    }
    if (bmin < -1e10) {
        d = bmin + 1e10;
    }
    for ()
    
    return 0;
}