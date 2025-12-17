#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<array<int, 2>> ans;
    int c0 = count(a.begin(), a.end(), 0);
    if (c0 == 0) {
        ans.push_back({0, n});
    } else if (c0 == 1) {
        int p = find(a.begin(), a.end(), 0) - a.begin();
        if (p == n - 1) {
            ans.push_back({p - 1, p + 1});
        } else {
            ans.push_back({p, p + 2});
        }
        ans.push_back({0, n - 1});
    } else {
        int p = n, q = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                p = min(p, i);
                q = max(q, i);
            }
        }
        if (p == 0 and q == n - 1) {
            ans.push_back({0, 2});
            ans.push_back({1, n - 1});
            ans.push_back({0, 2});
        } else {
            ans.push_back({p, q + 1});
            ans.push_back({0, n - q + p});
        }
    }

    cout << ans.size() << "\n";
    for (auto [l, r] : ans) {
        cout << l + 1 << " " << r << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}