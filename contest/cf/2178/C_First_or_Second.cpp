#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] - a[i];
    }

    i64 ans = -inf;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sum + pre[n] - pre[i + 1]);
        if (i == 0) {
            sum += a[i];
        } else {
            sum += std::abs(a[i]);
        }
    }
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