#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, D;
    cin >> n >> D;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<ll> sx(n + 1), sy(n + 1);
    for (int i = 1; i <= n; i++) {
        sx[i] = 1ll * x[i - 1] + sx[i - 1];
        sy[i] = 1ll * y[i - 1] + sy[i - 1];
    }

    vector<ll> cnt(D + 1);

    for (int i = -2e6; i <= 2e6; i++) {
        int t = upper_bound(y.begin(), y.end(), i) - y.begin();
        ll dist = 1ll * i * t - sy[t] + sy[n] - sy[t] - 1ll * (n - t) * i;
        if (dist > D)
            continue;
        cnt[dist]++;
    }

    for (int i = 1; i <= D; i++) {
        cnt[i] += cnt[i - 1];
    }

    ll res = 0;
    for (int i = -2e6; i <= 2e6; i++) {
        int t = upper_bound(x.begin(), x.end(), i) - x.begin();
        ll dist = 1ll * i * t - sx[t] + sx[n] - sx[t] - 1ll * (n - t) * i;
        if (dist > D)
            continue;
        assert(dist >= 0);
        res += cnt[D - dist];
    }

    cout << res << endl;
    
    return 0;
}