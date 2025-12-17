#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int x = sqrt(n);
    if (x * x != n) {
        cout << "No" << endl;
        return;
    }
    
    string t;
    for (int i = 0; i < x; i++) {
        t.push_back('1');
    }
    for (int i = 1; i < x - 1; i++) {
        t.push_back('1');
        for (int j = 1; j < x - 1; j++) {
            t.push_back('0');
        }
        t.push_back('1');
    }
    for (int i = 0; i < x; i++) {
        t.push_back('1');
    }
    cout << (s == t ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}