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

    string s;
    cin >> s;

    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + (s[i] == 'a' ? 1 : -1);
    }

    int sum = f[n];
    int ans = n;

    vector<int> pos(2 * n + 1, -1);
    for (int i = 0; i <= n; i++) {
        pos[f[i] + n] = i;
        auto need = f[i] - sum;
        if (need < -n or need > n or pos[need + n] == -1) {

        } else {
            ans = min(ans, i - pos[need + n]);
        }
    }

    if (ans == n) {
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