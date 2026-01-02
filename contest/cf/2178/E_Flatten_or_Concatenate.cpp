#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

i64 query(int l, int r) {
    cout << "? " << l + 1 << " " << r << endl;
    i64 ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;

    bool found = false;

    [&](this auto &&self, int l, int r, i64 sum) -> void {
        if (r - l == 1) {
            cout << "! " << sum << endl;
            found = true;
        }

        if (found) {
            return;
        }
        
        int lo = l + 1, hi = r + 1;
        while (lo < hi) {
            int x = midpoint(lo, hi);
            auto res = query(l, x);
            if (res >= sum / 2) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }

        if (lo - l > r - lo) {
            self(lo, r, sum / 2);
        } else {
            self(l, lo, sum / 2);
        }
    } (0, n, query(0, n));
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