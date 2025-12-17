#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    int k = n / 2;

    i64 base = 0;
    for (int i = 0; i < n; i++) {
        base += r[i] - l[i];
    }    

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans -= l[i];
    }
    
    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return l[i] + r[i] < l[j] + r[j];
    });

    for (int i = 0; i < k; i++) {
        int j = ord[n - 1 - i];
        ans += l[j] + r[j];
    }

    int nj = ord[n - 1 - k];

    i64 add = 0;
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            int j = ord[i];

            i64 res = 0;
            if (n - i <= k) {
                res -= r[j];
                res += l[nj] + r[nj];
            } else {
                res += l[j];
            }
            add = max(add, res);
        }
    }
    ans += add;

    ans += base;
    cout << ans << "\n";
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
