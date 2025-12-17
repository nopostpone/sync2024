#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;

    if (x > y or (x == y and a < b)) {
        swap(a, b);
        swap(x, y);
    }

    int ans = 0;
    if (k >= a) {
        ans += (k - a) / x + 1;
        k -= ans * x;
    }
    // cerr << k << endl;
    if (k >= b) {
        ans += (k - b) / y + 1;
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