#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 2e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto b = a;
    ranges::sort(b);

    vector<int> vec;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            vec.push_back(a[i]);
        }
    }

    int ans = inf;
    for (auto x : vec) {
        ans = min(ans, max(b[n - 1] - x, x - b[0]));
    } 
    if (ans == inf) {
        ans = -1;
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