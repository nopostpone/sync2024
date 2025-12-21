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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    unordered_map<int, pair<int, int>> f;
    vector<pair<int, int>> ope;

    for (int i = 0; i < n; i++) {
        if (f.contains(a[i])) {
            auto [j, t] = f[a[i]];
            if (t) {
                ope.emplace_back(j, j);
                swap(a[j], b[j]);
            }
            f.erase(a[i]);
            ope.emplace_back(i, j);
            f[b[j]] = {i, 0};
            swap(a[i], b[j]);
        } else {
            f[a[i]] = {i, 0};
        }

        if (not f.contains(b[i])) {
            f[b[i]] = {i, 1};
        } else {
            auto [j, t] = f[b[i]];
            f.erase(b[i]);
            if (i == j) {
                continue;
            }
            if (not t) {
                ope.emplace_back(j, j);
                swap(a[j], b[j]);
            }
            ope.emplace_back(j, i);
            f[a[j]] = {i, 1};
            swap(b[i], a[j]);
        }
    }

    if (not f.empty()) {
        cout << -1 << "\n";
        return;
    }

    i64 ans = 0;
    for (auto [x, y] : ope) {
        ans += std::abs(x - y);
    }
    cout << ans << " " << ope.size() << "\n";
    for (auto [x, y] : ope) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
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