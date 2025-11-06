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

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i] %= k;
    }
    ranges::sort(t);

    int l = lower_bound(t.begin(), t.end(), k - t[n - 1]) - t.begin();
    l = min(l, n - 1);
    int r = n - 1;

    i64 ans = 0;
    for (int i = 1; i <= l; i++) {
        ans += t[0] + t[i];
    }

    while (l < r) {
        while (l < r and t[l] + t[r] >= k) {
            ans += t[l] + t[r] - k;
            r--;
        }
        l++;
        while (l <= r) {
            ans += t[l] + t[r + 1] - k;
            if (t[l] + t[r] >= k) {
                break;
            }
            l++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

