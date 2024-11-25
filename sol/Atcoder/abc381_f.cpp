#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<set<int>> pos(20);
    for (int i = 0; i < n; i++) {
        pos[a[i]].insert(i);
    }

    vector dp(1 << 20, inf);
    dp[0] = 0;

    int res = 0;
    for (int s = 0; s < (1 << 20); s++) {
        if (dp[s] == inf) {
            continue;
        }
        int sum = 0;
        for (int i = 0; i < 20; i++) {
            sum += ((s >> i) & 1);
        }
        res = max(sum, res);

        for (int i = 0; i < 20; i++) {
            if ((s >> i) & 1) {
                continue;
            }
            auto nxt = pos[i].lower_bound(dp[s]);
            if (nxt != pos[i].end() and next(nxt) != pos[i].end()) {
                dp[s + (1 << i)] = min(dp[s + (1 << i)], *next(nxt));
            }
        }
    }

    cout << 2 * res << "\n";
    
    return 0;
}