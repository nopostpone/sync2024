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
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        vec[a[i]].push_back(i);
    }
    
    int ans = 0;
    
    for (int i = n - 1, j = n; i >= 0; i--) {
        while (not vec[i].empty() and vec[i].back() >= j) {
            vec[i].pop_back();
        }
        if (not vec[i].empty()) {
            ans += vec[i].size();
            j = vec[i][0];
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
}