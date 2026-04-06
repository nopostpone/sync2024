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

    string s, t;
    cin >> s >> t;

    const int n = s.size(), m = t.size();

    i64 ans = i64(n) * (n + 1) / 2;
    
    for (int l = 0; l < n; l++) {
        int p = 0, r = l;
        while (r < n) {
            if (s[r] == t[p]) {
                p++;
            }
            if (p == m) {
                break;
            }
            r++;
        }
        ans -= n - r;
    }
    cout << ans << "\n";
}