#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    i64 n;
    int k;
    cin >> n >> k;

    i64 sum = 0;
    bool ok = true;
    for (int i = 0; i < 2 * k; i++) {
        i64 a;
        cin >> a;
        sum += a;

        if (i % 2 == 0 and sum < n * (i / 2 + 1)) {
            ok = false;
        }
    }
    ok &= sum == n * k;
    cout << (ok ? "Yes" : "No") << "\n";
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