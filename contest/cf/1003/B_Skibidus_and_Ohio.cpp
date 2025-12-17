#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cout << 1 << "\n";
            return;
        }
    }
    cout << s.size() << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}