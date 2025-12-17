#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int l = 0, r = n;
    int cnt = 0;
    for (auto c : s) {
        if (c == '0') {
            l++;
        } else if (c == '1') {
            r--;
        } else {
            cnt++;
        }
    }

    string ans(n, '+');
    for (int i = 0; i < l; i++) {
        ans[i] = '-';
    }
    for (int i = r; i < n; i++) {
        ans[i] = '-';
    }
    if (k == n) {
        for (int i = l; i < r; i++) {
            ans[i] = '-';
        }
    }

    for (int i = l; i < l + cnt; i++) {
        if (ans[i] == '+') {
            ans[i] = '?';
        }
    }
    for (int i = r; i >= r - cnt; i--) {
        if (ans[i] == '+') {
            ans[i] = '?';
        }
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

    return 0;
}