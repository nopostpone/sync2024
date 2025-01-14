#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    ll ans = 2e18;

    constexpr int p[] = {
        2, 3, 5, 7, 11, 13, 17, 19,
        23, 29, 31, 37, 41, 43, 47, 53};

    auto dfs = [&](auto &self, ll dep, ll t, int num, ll up) -> void {
        if (dep >= 16 or num > n) {
            return;
        }
        if (num == n) {
            ans = min(ans, t);
            return;
        }
        for (int i = 1; i <= up; i++) {
            if (1ull * t * p[dep] > 1ull * ans) {
                break;
            }
            t = t * p[dep];
            self(self, dep + 1, t, num * (i + 1), i);
        }
    };
    dfs(dfs, 0, 1, 1, 63);
    cout << ans << "\n";

    return 0;
}