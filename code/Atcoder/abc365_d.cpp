// https://atcoder.jp/contests/abc365/tasks/abc365_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S')
            a[i] = 0;
        else if (s[i] == 'R')
            a[i] = 1;
        else
            a[i] = 2;
    }
    vector f(n, vector<int>(3));
    f[0][a[0]] = 0;
    f[0][(a[0] + 1) % 3] = 1;
    for (int i = 1; i < n; i++) {
        f[i][a[i]] = max(f[i - 1][(a[i] + 1) % 3], f[i - 1][(a[i] + 2) % 3]);
        f[i][(a[i] + 1) % 3] = max(f[i - 1][(a[i] + 2) % 3], f[i - 1][(a[i] + 3) % 3]) + 1;
    }
    cout << *max_element(f[n - 1].begin(), f[n - 1].end());
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}