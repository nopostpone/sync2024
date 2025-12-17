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

    int n;
    cin >> n;

    vector<tuple<int, i64, i64>> a(n);
    i64 vsum = 0, wsum = 0;
    for (auto &[w, v, c] : a) {
        cin >> w >> v >> c;
        vsum += v;
        wsum += w;
    }

    ranges::sort(a, [](auto x, auto y) {
        auto [xw, xv, xc] = x;
        auto [yw, yv, yc] = y;
        return (i64)xw * yc < (i64)yw * xc;
    });

    i64 ans = vsum;
    for (auto [w, v, c] : a) {
        wsum -= w;
        ans -= wsum * c;
    }
    cout << ans << "\n";

    return 0;
}