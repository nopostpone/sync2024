#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, t0;
    cin >> n >> t0;

    string s;
    cin >> s;

    multiset<int> a;
    for (int l = 0, r; l < n; l = r) {
        r = l + 1;
        while (r <= n and s[r - 1] == '0') {
            r++;
        }
        if (r - l - 1 > 0) {
            a.insert(r - l - 1);
        }
    }
    {
        int p = s.find('1');
        int q = s.find_last_of('1');
        if (p != 0 and q != n - 1) {
            a.extract(p);
            a.extract(n - q - 1);
            a.insert(p + n - q - 1);
        }
    }

    if (a.empty()) {
        cout << 0 << "\n";
        return;
    }

    int mx = *a.rbegin();
    a.extract(mx);

    int ans = 0;
    for (auto x : a) {
        ans += max(0, x - 2 * t0);
    }
    ans += max(0, mx - 1 - t0);
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