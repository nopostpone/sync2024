#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 3) {
        if ((int)s.find_last_of('1') > 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
        return;
    }
    if (s[n - 1] == '0' and s[n - 2] == '0') {
        cout << "Yes\n";
        return;
    }

    vector<int> b;
    for (int i = n - 4; i >= 0; i--) {
        if (s[i] == '1') {
            b.push_back(i);
        }
    }

    int x = 0;
    for (int i = n - 3; i < n; i++) {
        if (s[i] == '1') {
            x = i;
            break;
        }
    }
    bool ok = x == 0;

    for (int i = 0; i < b.size(); i++) {
        if (b[i] >= x - 2 * (i + 1)) {
            ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
6 6
1 3
1 4
2 3
3 4
3 6
5 6
1 2 3 4 5 6

*/