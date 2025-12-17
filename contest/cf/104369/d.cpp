#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<LL, 3>> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = a[i][1] - a[i][0];
    }

    sort(a.begin() + 1, a.end(), [&](array<LL, 3> x, array<LL, 3> y){
        return x[2] > y[2];
    });
    int dif = m - n;
    if(dif >= m / 2) dif = (m + 1) / 2;

    bool ok = false;
    LL ans = 0;
    for(int i = 1; i <= min(n, dif); i++){
        if(a[i][2] > 0) ans += a[i][1];
        else{
            if(ok || i + 1 <= n){
                ok = true;
                ans += a[i][0];
            }else ans += a[i][1];
        }
    }
    if(dif + 2 <= n) ok = true;
    for(int i = dif + 1; i <= n; i++){
        if(ok) ans += a[i][0];
        else ans += a[i][1];
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
/*
1
2 5
1 100
1 100
*/