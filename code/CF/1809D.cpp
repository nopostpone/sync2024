#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 X = 1e12;

void solve() {
    string s;
    cin >> s;

    const int n = s.size();
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    int c0 = 0, c1 = count(s.begin(), s.end(), '1');

    i64 ans = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
            c0++;
        } else {
            c1--;
        }

        // cerr << i + 1 - c0 << " " << n - i - 1 - c1 << endl;
        // 0001 | 1111 左边少删一个 1
        // 0000 | 0111 右边少删一个 0

        i64 res = (X + 1) * (n - c0 - c1 - (s[i] == '1') - (s[i + 1] == '0'));
        if (s[i] > s[i + 1]) {
            res += X;
        }
        ans = min(ans, res);
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