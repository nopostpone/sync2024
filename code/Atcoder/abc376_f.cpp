#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> dp(n, inf);
    dp[1] = 0;
    
    int x = 0, ph = 0;
    for (int i = 0; i < q; i++) {
        char c;
        int t;
        cin >> c >> t;
        t--;
        bool h = c == 'R';

        vector<int> ndp(n, inf);
        
        auto upd = [&](int x, int y, int a, int d) {
            int dx = (a - x + n) % n;
            int dy = (a - y + n) % n;
            if (dx >= dy) {
                ndp[(a + 1) % n] = min(ndp[(a + 1) % n], d + dx + dy + 1);
            } else {
                ndp[y] = min(ndp[y], d + dx);
            }

            dx = (x - a + n) % n;
            dy = (y - a + n) % n;
            if (dx >= dy) {
                ndp[(a - 1 + n) % n] = min(ndp[(a - 1 + n) % n], d + dx + dy + 1);
            } else {
                ndp[y] = min(ndp[y], d + dx);
            }
        };

        if (h == ph) {
            for (int j = 0; j < n; j++) {
                if (dp[j] != inf) {
                    upd(x, j, t, dp[j]);
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (dp[j] != inf) {
                    upd(j, x, t, dp[j]);
                }
            }
        }
        ph = h;
        x = t;
        dp = ndp;
    }
    

    cout << *min_element(dp.begin(), dp.end()) << endl;

    return 0;
}