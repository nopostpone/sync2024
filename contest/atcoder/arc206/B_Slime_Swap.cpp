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

    int n;
    cin >> n;

    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;

        vec[c[i]].push_back(p[i]);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> lis;
        for (auto x : vec[i]) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }

        ans += i64(vec[i].size() - lis.size()) * (i + 1);
    }
    cout << ans << "\n";

    return 0;
}