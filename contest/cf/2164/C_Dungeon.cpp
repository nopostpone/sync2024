#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m), c(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    for (auto &x : c) {
        cin >> x;
    }

    multiset<int> s(a.begin(), a.end());
    int ans = 0;

    vector<pair<int, int>> f1, f2;
    for (int i = 0; i < m; i++) {
        (c[i] ? f1 : f2).emplace_back(b[i], c[i]);
    }
    ranges::sort(f1);
    ranges::sort(f2);

    for (auto [b, c] : f1) {
        auto it = s.lower_bound(b);
        if (it != s.end()) {
            ans++;
            s.insert(max(*it, c));
            s.erase(it);
        }
    }
    for (auto [b, c] : f2) {
        auto it = s.lower_bound(b);
        if (it != s.end()) {
            ans++;
            s.erase(it);
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