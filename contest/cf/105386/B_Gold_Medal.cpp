#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] / k;
        a[i] %= k;
    }
    int m;
    cin >> m;

    ranges::sort(a, greater());

    for (int i = 0; i < n and m != 0; i++) {
        if (k - a[i] > m) {
            break;
        } else {
            m -= k - a[i];
            ans++;
        }
    }
    ans += m / k;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}