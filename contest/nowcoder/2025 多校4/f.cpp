#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, c;
    cin >> n >> k >> c;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= (i64)i * c;
    }
    ranges::sort(a, greater());
    i64 ans = 0;
    for (int i = 0; i < k; i++) {
        ans += a[i];
        ans += (i64)i * c;
    }
    cout << ans << "\n";
    
    return 0;
}