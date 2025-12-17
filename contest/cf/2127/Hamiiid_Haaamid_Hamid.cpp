#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, x;
    cin >> n >> x;
    x--;

    string s;
    cin >> s;

    int rp = x;
    while (rp < n and s[rp] != '#') {
        rp++;
    }
    int lp = x;
    while (lp >= 0 and s[lp] != '#') {
        lp--;
    }
    int l = lp + 2;
    int r = n + 1 - rp;
    if (l > r) {
        r = n - x;
    } else {
        l = x + 1;
    }
    cout << min(l, r) << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}