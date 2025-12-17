#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    const int n = s.length();

    vector pre(n + 1, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pre[i + 1][j] = pre[i][j] + (s[i] == char(j + 'A'));
        }
    }
    ull ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            int l = pre[i - 1][j];
            int r = pre[n][j] - pre[i][j];
            ans += 1ll * l * r;
        }
    }

    cout << ans << endl;

    return 0;
}