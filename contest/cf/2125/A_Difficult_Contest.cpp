#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    string s;
    cin >> s;

    for (auto c : s) {
        if (c == 'T') {
            cout << c;
        }
    }
    for (auto c : s) {
        if (c != 'T') {
            cout << c;
        }
    }
    cout << "\n";
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