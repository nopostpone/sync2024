#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 需要更频繁地分类讨论，拆解问题

void solve() {
    string s;
    cin >> s;

    const int n = s.size();
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cout << "YES" << "\n";
            for (int j = 0; j < n; j++) {
                cout << "()";
            }
            cout << "\n";
            return;
        }
    }

    if (s == "()") {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << '(';
        }
        for (int i = 0; i < n; i++) {
            cout << ')';
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}