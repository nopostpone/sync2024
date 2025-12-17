#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int x, y;
    cin >> x >> y;

    while (true) {
        if ((x + y) % 2) {
            cout << -1 << "\n";
            return;
        }
        int g = __gcd(x, y);
        x /= g;
        y /= g;

        if (x == 1 or y == 1) {
            break;
        }
    }

    if (x > y) {
        swap(x, y);
    }

    int z = y + 1;
    if ((1 << __lg(z)) == z) {
        cout << __lg(z) << "\n";
    } else {
        cout << -1 << "\n";
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