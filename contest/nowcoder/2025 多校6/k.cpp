#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (count(a.begin(), a.end(), a[0]) == n) {
        cout << 0 << "\n";
        return;
    }

    unordered_map<int, int> pre;
    pre[0] = -1;
    {
        int g = 0;
        for (int i = 0; i < n; i++) {
            g = std::gcd(g, a[i]);
            pre[g] = i;
        }
    }
    unordered_map<int, int> suf;
    suf[0] = n;
    {
        int g = 0;
        for (int i = n - 1; i >= 0; i--) {
            g = std::gcd(g, a[i]);
            suf[g] = i;
        }
    }

    auto work = [&](int l, int r, int g) {
        if (l >= r) {
            return g;
        }
        int mn = *min_element(a.begin() + l, a.begin() + r);
        int res = g;
        for (int i = l; i < r; i++) {
            res = std::gcd(res, a[i] - mn);
        }
        return res;
    };

    int ans = 0;
    for (int i = 0, mn = ranges::min(a); i < n; i++) {
        ans = std::gcd(ans, a[i] - mn);
    }

    for (auto [gl, l] : pre) {
        for (auto [gr, r] : suf) {
            if (gl == 0 and gr == 0) {
                continue;
            }
            int g = std::gcd(gl, gr);
            if (g == 1) {
                continue;
            }
            ans = max(ans, work(l + 1, r, g));
        }
    }
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

    return 0;
}