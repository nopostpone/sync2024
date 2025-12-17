#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok = false;
    do {
        for (auto x : a) {
            if (x & 1) {
                ok = true;
            }
        }
        if (not ok) {
            for (auto &x : a) {
                x /= 2;
            }
        }
    } while (not ok);

    int ans = INT_MAX;
    for (auto x : a) {
        if (x & 1) {
            ans = min(ans, x);
        }
    }
    cout << (ans + 1) / 2 << "\n";

    return 0;
}