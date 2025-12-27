#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int ans = 1e9;
    for (int i = 0; i + m <= n; i++) {
        int res = 0;
        for (int j = 0; j < m; j++) {
            res += (s[i + j] - t[j] + 10) % 10;
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";

    return 0;
}