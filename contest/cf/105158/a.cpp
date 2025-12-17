#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

constexpr i64 ori = 1234567890;

void solve() {
    int n, d;
    cin >> n >> d;

    i64 ans = ori + d;
    for (int i = n; i; i /= 10) {
        ans *= 10;
    }
    ans = (ans + n - 1) / n;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
3
1 6
12345678 9
233 2
*/