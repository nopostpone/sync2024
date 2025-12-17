#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            ans++;
        } else {
            ans += a;
        }
    }    
    cout << ans << "\n";
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