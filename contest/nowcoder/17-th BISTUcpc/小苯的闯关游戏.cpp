#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int k) {
        int cur = k;
        for (auto x : a) {
            if (cur > x) {
                cur++;
            } else if (cur < x) {
                cur--;
            }
        }

        return cur > k;
    };

    int lo = 0, hi = 2e9;
    while (lo < hi) {
        int x = lo + (hi - lo) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    cout << lo << "\n";
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