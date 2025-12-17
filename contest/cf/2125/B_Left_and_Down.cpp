#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    i64 a, b, k;
    cin >> a >> b >> k;

    i64 ans = 0;
    i64 g = __gcd(a, b);

    if (a / g <= k and b / g <= k) {
        ans = 1;
    } else {
        ans = 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}