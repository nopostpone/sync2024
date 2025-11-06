#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e3;

string s, t;
int n;

void solve() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' and t[i] == '1') {
            cout << "NO" << endl;
            return;
        }
        if (s[i] == '1') {
            cout << "yes" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}