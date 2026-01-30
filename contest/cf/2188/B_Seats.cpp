#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // n += 2;
    // s = '0' + s + '0';

    int ans = count(s.begin(), s.end(), '1');

    for (int i = 0, j; i < n; ) {
        if (s[i] == '1') {
            i++;
            continue;
        }
        j = i;
        while (j < n and s[j] == '0') {
            j++;
        }
        int len = j - i;
        if (i != 0) {
            len--;
        }
        if (j != n) {
            len--;
        }

        ans += (len + 2) / 3;
        i = j;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}