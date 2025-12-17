#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    string s;
    cin >> s;

    i64 S = stoll(s);

    const int n = s.size();

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    reverse(a.begin(), a.end());

    int ans = 10;

    auto check = [&](i64 x) {
        while (x) {
            if (x % 10 == 7) {
                return true;
            }
            x /= 10;
        }
        return false;
    };

    for (i64 i = 9; i <= 1e11; i = i * 10 + 9) {
        i64 now = S;
        for (int j = 0; j <= ans; j++) {
            if (check(now)) {
                ans = min(ans, j);
                break;
            } else {
                now += i;
            }
        }
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