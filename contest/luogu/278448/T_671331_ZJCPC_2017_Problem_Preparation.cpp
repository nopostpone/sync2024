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

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    if (n < 10 or n > 13) {
        cout << "No\n";
        return;
    }

    ranges::sort(s);
    if (not (s[0] == 1 and s[1] == 1)) {
        cout << "No\n";
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i] - s[i - 1] > 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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