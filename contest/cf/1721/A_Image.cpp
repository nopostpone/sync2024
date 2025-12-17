#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    string s[2];
    cin >> s[0] >> s[1];

    vector<int> f(26);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            f[s[i][j] - 'a']++;
        }
    }
    ranges::sort(f, greater());
    int ans;
    if (f[0] == 4) {
        ans = 0;
    } else if (f[0] == 3) {
        ans = 1;
    } else if (f[0] == 2 and f[1] == 2) {
        ans = 1;
    } else if (f[0] == 2) {
        ans = 2;
    } else {
        ans = 3;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}