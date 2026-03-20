#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    array<int, 3> a;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            for (int k = j; k < 3; k++) {
                auto x = a[i];
                auto y = a[j];
                auto z = a[k];
                ans += x + y > z and x + z > y and y + z > x;
            }
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
}