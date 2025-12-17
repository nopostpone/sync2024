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

    const int n = s.size();

    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + (s[i] == '(' ? 1 : -1);
    }
    for (int i = 0; i <= n; i++) {
        if (f[i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    if (f[n] != 0) {
        cout << "NO\n";
        return;
    }

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        if (f[i + 1] == 0 and i != n - 1) {
            cout << "NO\n";
            return;
        }
        if (s[i] == '(') {
            cnt[f[i + 1]]++;
        } else {
            cnt[f[i + 1] + 2] = 0;
        }
        if (cnt[f[i + 1]] > 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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