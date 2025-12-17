#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool ok = true;
    if (n % 2 == 0) {
        ok = false;
    } else {
        for (int i = 0; i < (n + 1) / 2 - 1; i++) {
            if (s[i] != '1') {
                ok = false;
            }
        }
        if (s[(n + 1) / 2 - 1] != '/') {
            ok = false;
        }
        for (int i = n - 1; ok and s[i] != '/'; i--) {
            if (s[i] != '2') {
                ok = false;
            }
        }
    }

    cout << (ok ? "Yes" : "No");
    
    return 0;
}