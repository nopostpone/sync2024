#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 2) {
        cout << a[0] + min(a[0], a[1]) << "\n";
        return;
    }
    if (a[0] >= a[1]) {
        cout << a[0] + a[1] << "\n";
    } else {
        cout << 2 * a[0] << "\n";
    }
    

    // i64 ans = inf;
    // int cur = a[0];
    // for (int i = 0; i < n; i++) {
        

    //     cur = min(cur, a[i]);

    // }
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