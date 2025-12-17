#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;

    if ((sx - 1 > d and sy + d < m) or (sy - 1 > d and sx + d < n)) {
        cout << n + m - 2 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}