#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int ans = 0;
    if (s[0] == 'u') {
        s[0] = 's';
        ans++;
    }
    if (s[n - 1] == 'u') {
        s[n - 1] = 's';
        ans++;
    }

    for (int l = 0, r; l < n; l = r) {
        r = l + 1;
        while (r <= n and s[r - 1] == 'u') {
            r++;
        }
        ans += (r - l - 1) / 2;
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