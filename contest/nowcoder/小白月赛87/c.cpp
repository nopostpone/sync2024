#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int now;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I')
            now = i;
    }

    int l = now - 1;
    int r = now + 1;

    while (m--) {
        string op;
        cin >> op;
        // cerr << l << " " << r << endl;
        if (op == "backspace") {
            if (l < 0) {
                continue;
            }
            l--;
            if (r >= n) {
                continue;
            }
            if (s[l + 1] == '(' and s[r] == ')') {
                r++;
            }
        } else {
            if (r >= n) {
                continue;
            }
            r++;
        }
    }

    if (l >= 0) {
        cout << s.substr(0, l + 1);
    }
    cout << s[now];
    if (r < n) {
        cout << s.substr(r, n - r + 100) << endl;
    }
    return 0;
}