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

    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    ranges::sort(s);
    ranges::sort(t);

    if (s == t) {
        cout << "Yes\n";
        return;
    }

    bool ok = false;
    for (int i = 1; i < n; i++) {
        if (s[i] - s[i - 1] == 1) {
            ok = true;
        }
    }
    if (not ok) {
        cout << "No\n";
        return;
    }
    ok = false;
    for (int i = 1; i < n; i++) {
        if (t[i] - t[i - 1] == 1) {
            ok = true;
        }
    }
    if (not ok) {
        cout << "No\n";
        return;
    }

    int even = 0, odd = 0;
    for (auto x : s) {
        (x % 2 ? odd : even)++;
    }
    for (auto x : t) {
        (x % 2 ? odd : even)--;
    }

    cout << (even == 0 and odd == 0 ? "Yes" : "No") << "\n";
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