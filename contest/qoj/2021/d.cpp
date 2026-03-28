#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> c[i];
    }

    string ans;
    for (int i = 0; i <= n; i++) {
        while (i and c[i - 1] > 1) {
            ans += "LR";
            c[i - 1]--;
            c[i]--;
        }
        if (i != n) {
            ans += "R";
            c[i + 1]--;
        }
    }

    if (count(c.begin(), c.begin() + n, 1) != n or c.back() != 0) {
        ans = "Impossible";
    } else {
        ans += string(n, 'L');
    }
    cout << ans << "\n";
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