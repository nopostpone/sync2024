#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (abs(a[i + 1] - a[i]) <= 1) {
            cout << 0 << "\n";
            return;
        }
    }

    if (is_sorted(a.begin(), a.end()) or is_sorted(a.begin(), a.end(), greater())) {
        cout << -1 << "\n";
    } else {
        cout << 1 << "\n";
    }
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