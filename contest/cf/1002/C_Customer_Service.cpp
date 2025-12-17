#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == 1) {
                x++;
            } else {
                break;
            }
        }
        b.push_back(x);
    }

    ranges::sort(b);
    int ans = 0;
    for (auto x : b) {
        if (x >= ans) {
            ans++;
        }
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