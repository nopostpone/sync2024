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

    if (s[0] == s[2]) {
        cout << "No\n";
    } else
    if (s[1] == '-') {
        if (s[0] == '0' and s[0] != s[2]) {
            cout << "Yes\n"; 
        } else {
            cout << "No\n";
        }
    } else {
        cout << "Yes\n";
    }
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