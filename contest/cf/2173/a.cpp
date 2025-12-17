#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            for (int j = 0; j < k and i + j + 1 < n; j++) {
                s[i + j + 1] = '1';
            }
        }
    }

    cout << ranges::count(s, '0') << "\n";
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
