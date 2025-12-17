#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    string s;

    cin >> a >> b >> c >> s;

    int ans = 0;
    int cnt = 0;
    int cw = 0, ca = 0;
    bool com = true;
    for (auto cc : s) {
        if (cc == 'G') {
            ans += a;
            com = false;
        } else if (cc == 'B') {
            ans += a;
            if (ca >= 1 or cw >= 3) {
                cnt++;
            }
            ca = 0;
            cw = 0;
            com = true;
        } else if (cc == 'A') {
            ans += b;
            ca++;
        } else {
            ans += c;
            cw++;
        }
    }
    int t = 2 * a + min(3 * c, b);
    // cerr << t << endl;
    if (com) {
        ans += t * max(0, 4 - cnt);
    } else {
        ans += t * max(0, 3 - cnt);
        ans += a;
        if (ca == 0 and cnt < 4) {
            int u = b;
            int v = c * max(3 - cw, 0);
            // cerr << u << " " << v << endl;
            ans += min(u, v);
        }
    }
    
    cout << ans << "\n";

    return 0;
}