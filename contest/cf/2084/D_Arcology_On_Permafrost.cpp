#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int mx = 0;

    int rest = n - m * k;
    if (rest < k) {
        mx = rest;
        for (int i = 0; i < n; i++) {
            cout << (i % k) << " \n"[i == n - 1];
        }
    } else {
        int u = n / (m + 1);
        mx = u;
        for (int i = 0; i < n; i++) {
            cout << (i % mx) << " \n"[i == n - 1];
        }
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