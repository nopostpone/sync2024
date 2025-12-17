#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 0;
    if (k == 1) {
        i64 u = 0;
        if (n > 2) {
            u = *max_element(a.begin() + 1, a.end() - 1);
        }
        ans = max(u + max(a[0], a[n - 1]), 1ll * a[0] + a[n - 1]);
    } else {
        ranges::sort(a, greater());
        for (int i = 0; i < k + 1; i++) {
            ans += a[i];
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}