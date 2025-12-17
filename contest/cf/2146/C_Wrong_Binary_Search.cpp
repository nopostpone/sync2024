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

    string s;
    cin >> s;

    vector<int> a(n);
    ranges::iota(a, 0);

    for (int l = 0, r; l < n; l = r + 1) {
        r = l;
        while (r <= n and s[r] == '0') {
            r++;
        }
        if (l == r) {
            continue;
        }
        if (r - l == 1) {
            cout << "NO\n";
            return;
        }
        reverse(a.begin() + l, a.begin() + r);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " \n"[i == n - 1];
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