#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

void solve() {
    int n, k, s, t;
    cin >> n >> k >> s >> t;

    int l = s, r = s;
    int d = 2 * min(k, n - k);

    int ans = inf;
    for (int i = 0; i < 2; i++) {
        if (l % 2 == t % 2) {
            if (l <= t and t <= r) {
                ans = min(ans, i);
            } else if (d > 0) {
                if (t < l) {
                    int c = (l - t - 1) / d + 1;
                    ans = min(ans, c * 2 + i);
                }
                if (t > r) {
                    int c = (t - r - 1) / d + 1;
                    ans = min(ans, c * 2 + i);
                }
            }
        }
        l = abs(l - k);
        r = n - abs(n - (r + k));
    }    

    if (ans == inf) {
        ans = -1;
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
