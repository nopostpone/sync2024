#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using p32 = pair<int, int>;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    set<int> s;
    for (int i = 0; i < n - 1; i++) {
        int nb = gcd(b[i], b[i + 1]);
        if (nb != b[i]) {
            int d = b[i] / nb;
            s.insert(d);
        }
    }

    int ans = 1;
    for (auto x : s) {
        int g = __gcd(ans, x);
        ans *= x / g;
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