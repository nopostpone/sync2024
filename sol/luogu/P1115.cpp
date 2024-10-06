#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = -2e9;

    ll t = 0;
    for (int i = 0; i < n; i++) {
        t = max<ll>(a[i], t + a[i]);
        ans = max(ans, t);    
    }

    cout << ans << endl;

    return 0;
}