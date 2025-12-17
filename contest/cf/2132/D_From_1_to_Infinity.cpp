#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    i64 k;
    cin >> k;

    i64 ans = 0;
    for (i64 n = 1, i = 1; k - n * i * 9 >= 0; n++, i *= 10) {
        k -= n * i * 9;
        ans += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}