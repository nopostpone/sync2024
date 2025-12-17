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

    vector<int> a(n);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }

    int v = ranges::max(a);
    
    for (int d = __lg(v); d >= 0; d--) {
        vector<int> na;
        for (auto x : a) {
            if (x >> d & 1) {
                na.push_back(x);
            }
        }
        if (na.size() >= 2) {
            ans -= 1 << (d + 1);
            a = move(na);
        }
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