#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = (pre[i] + a[i]) % m;
    }

    vector<int> cnt(m);
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += cnt[(pre[i] - pre.back() + m) % m];
        ans += cnt[pre[i]];
        cnt[pre[i]]++;
    }

    cout << ans << endl;

    return 0;
}