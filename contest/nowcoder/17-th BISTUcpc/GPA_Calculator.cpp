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

    cout << fixed << setprecision(2);

    double x;
    cin >> x;

    double ans = 0;
    if (x >= 60) {
        ans = 1;
        int d = 10 * x - 600;
        ans += 0.01 * d;
    }

    cout << ans << "\n";

    return 0;
}