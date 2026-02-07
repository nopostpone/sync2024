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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], i + a[i]);
    }

    auto check = [&](int tot) {
        int cnt = 0;

        for (int i = 0, t = 0; i < n;) {
            if (t == 0 and a[i] == 0) {
                while (i < n and a[i] == 0) {
                    i++;
                }
                continue;
            }
            if (t == 0) {
                cnt++;
            }
            if (t == tot) {
                i++;
                t = 0;
            } else {
                if (i == pre[i + 1]) {
                    t = 0;
                    i++;
                } else {
                    i = pre[i + 1];
                    t++;
                }
            }
        }

        return cnt <= k;
    };

    int lo = 0, hi = n;
    while (lo < hi) {
        int x = midpoint(lo, hi);
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    cout << (lo == n ? -1 : lo) << "\n";
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