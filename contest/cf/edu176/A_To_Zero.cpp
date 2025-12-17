#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    if (n % 2 == 1) {
        if (k % 2 == 1) {
            ans++;
            n -= k;
            k--;
            ans += (n + k - 1) / k;
        } else {
            ans++;
            n -= k - 1;
            ans += (n + k - 1) / k;
        }
    } else {
        if (k % 2 == 1) {
            k--;
        }
        ans = (n + k - 1) / k;
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