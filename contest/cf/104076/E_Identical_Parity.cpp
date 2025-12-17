#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    int x = n / k;
    int y = (n + k - 1) / k;
    int cx = k - (n % k);
    int cy = n % k;

    int t = n / 2;

    if (x * cx < y * cy) {
        swap(x, y);
        swap(cx, cy);
    }

    bool ok = true;
    if (x > y) {
        int a = (t + x - 1) / x * x - t;
        if (a > cy) {
            ok = false;
        }
    } else {
        int a = t - t / x * x;
        if (a > cy) {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}