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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto work = [&](int x) {
        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            auto cur = a[i];
            
            for (int j = 0; cur != 0; j++) {
                f[i] = min(f[i], std::abs(cur - x) + j);
                cur /= 2;
            }
        }

        ranges::sort(f);
        return accumulate(f.begin(), f.begin() + n - m, i64());
    };

    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        while (cur) {
            s.insert(cur);
            cur /= 2;
        }
    }

    i64 ans = 1e18;
    for (auto x : s) {
        ans = min(ans, work(x));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}