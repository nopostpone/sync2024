#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, xk, yk, xd, yd;
    cin >> n >> xk >> yk >> xd >> yd;

    int ans = 0;
    if (xk < xd) {
        ans = max(ans, xd);
    } else if (xk > xd) {
        ans = max(ans, n - xd);
    }

    if (yk < yd) {
        ans = max(ans, yd);
    } else if (yk > yd) {
        ans = max(ans, n - yd);
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