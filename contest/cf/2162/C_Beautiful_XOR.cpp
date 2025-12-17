#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int a, b;
    cin >> a >> b;

    int o1 = 0;
    int o2 = 0;
    for (int i = 0; i < 31; i++) {
        int u = a >> i & 1;
        int v = b >> i & 1;

        if (u - v == 1) {
            o1 |= 1 << i;
        }
        if (v - u == 1) {
            o2 |= 1 << i;
        }
    }
    if (o1 > a or o2 > a) {
        cout << -1 << "\n";
    } else {
        // assert((a ^ o2) >= o1);
        cout << 2 << "\n" << o2 << " " << o1 << "\n";
    }
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