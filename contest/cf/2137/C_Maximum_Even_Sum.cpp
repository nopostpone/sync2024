#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

auto check(i64 a, i64 b) {
    return (a + b) % 2 == 0;
}

void solve() {
    i64 a, b;
    cin >> a >> b;

    i64 ans = -1;
    if (check(a, b)) {
        ans = a + b;
    }
    if (check(a * b, 1)) {
        ans = a * b + 1;
    }
    if (b % 2 == 0) {
        if (check(a * b / 2, 2)) {
            ans = max(ans, a * b / 2 + 2);
        }
    }
    cout << ans << "\n";    
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