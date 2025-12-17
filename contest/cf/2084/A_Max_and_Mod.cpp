#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << "\n";
        return;
    }

    vector<int> a(n);
    a[1] = 1;
    a[0] = n;
    for (int i = 2; i < n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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