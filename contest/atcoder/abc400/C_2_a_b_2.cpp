#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    i64 ans = 0;
    i64 a = 1;
    while (2 * a <= n) {
        a *= 2;

        i64 lo = 0, hi = 1e9;
        while (lo < hi) {
            i64 m = (lo + hi) / 2;
            if (m * m > n / a) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        lo--;
        ans += (lo + 1) / 2;
    }
    cout << ans << "\n";

    return 0;
}