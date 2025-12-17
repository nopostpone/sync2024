#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    constexpr int V = 2e5 + 1;

    vector<vector<pair<int, int>>> add(V), cal(V); 
    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        add[l].emplace_back(r, c);
        cal[r].emplace_back(l, c);
    }

    vector<int> f(V, inf);
    int ans = INT_MAX;
    for (int i = V - 1; i >= 0; i--) {
        for (auto [r, c] : add[i]) {
            int len = r - i;
            f[len] = min(f[len], c);
        }
        for (auto [l, c] : cal[i]) {
            int tar = x - (i - l);
            if (tar <= 0 or f[tar] == inf) {
                continue;
            }
            ans = min(ans, f[tar] + c);
        }
    }
    if (ans > inf) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}
