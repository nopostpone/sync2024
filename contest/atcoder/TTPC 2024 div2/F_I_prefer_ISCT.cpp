#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < n; i++) {
        if (s.substr(i, 4) == "TIOT" and t[i] == 'I') {
            s[i] = 'I';
            s[i + 1] = 'S';
            s[i + 2] = 'C';
            s[i + 3] = 'T';
        }
    }

    cout << (s == t ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}