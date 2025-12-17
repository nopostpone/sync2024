#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            s.insert(i, 1, char(s[i] == 'z' ? 'a' : s[i] + 1));
            ok = false;
            break;
        }
    }
    if (ok) {
        if (s.back() != 'z') {
            s.push_back('z');
        } else {
            s.push_back('a');
        }
    }
    cout << s << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}