#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    bool g = true;
    for (int i = 0; i < m - 1; i++) {
        if (a[i] >= a[i + 1]) {
            g = false;
        }
    }

    if (g) {
        int x = a.back();
        cout << n - x + 1 << "\n";
    } else {
        cout << 1 << "\n";
    }
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