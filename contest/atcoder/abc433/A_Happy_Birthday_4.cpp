#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, z;
    cin >> x >> y >> z;

    bool ok = false;
    for (int t = 1; t <= 10000; x++, y++, t++) {
        if (x == z * y) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";

    return 0;
}