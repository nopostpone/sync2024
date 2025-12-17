#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    // hang
    for (int i = 0; i < 3; i++) {
        bool ook = true;
        int x = 0;
        for (int j = 0; j < 3; j++) {
            if (s[i][j] == 'X') {
                x++;
            } else if (s[i][j] == 'O') {
                ook = false;
            }
        }
        if (ook and x > 0) {
            cout << "Yes\n";
            return;
        }
    }
    // lie
    for (int i = 0; i < 3; i++) {
        bool ook = true;
        int x = 0;
        for (int j = 0; j < 3; j++) {
            if (s[j][i] == 'X') {
                x++;
            } else if (s[j][i] == 'O') {
                ook = false;
            }
        }
        if (ook and x > 0) {
            cout << "Yes\n";
            return;
        }
    }
    // duijioaxian
    {
        bool ok = true;
        int x = 0;
        for (int i = 0; i < 3; i++) {
            if (s[i][i] == 'O') {
                ok = false;
            } else if (s[i][i] == 'X') {
                x++;
            }
        }
        if (ok and x) {
            cout << "Yes\n";
            return;
        }
    }
    {
        bool ok = true;
        int x = 0;
        for (int i = 0; i < 3; i++) {
            if (s[i][2 - i] == 'O') {
                ok = false;
            } else if (s[i][2 - i] == 'X') {
                x++;
            }
        }
        if (ok and x) {
            cout << "Yes\n";
            return;
        }
    }
    // kong
    {
        int x = 0, y = 0;
        for (int i = 0; i < 3; i++) {
            bool o = true;
            bool k = true;
            for (int j = 0; j < 3; j++) {
                if (s[i][j] != 'G') {
                    o = false;
                }
                if (s[j][i] != 'G') {
                    k = false;
                }
            }
            x += o;
            y += k;
        }
        if (x > 0 and y > 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}