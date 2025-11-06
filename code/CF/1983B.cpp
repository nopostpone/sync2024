// https://codeforces.com/contest/1983/problem/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        int s = 0, t = 0;
        for (int j = 0; j < m; j++) {
            s += a[i][j] ^ 48;
            t += b[i][j] ^ 48;
        }
        if (s % 3 != t % 3) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        int s = 0, t = 0;
        for (int j = 0; j < n; j++) {
            s += a[j][i] ^ 48;
            t += b[j][i] ^ 48;
        }
        if (s % 3 != t % 3) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}