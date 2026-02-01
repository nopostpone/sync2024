#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto b = a;

    for (int i = 1; i < n; i++) {
        a[i] = min(a[i], a[i - 1] + 1);
    }
    for (int i = n - 2; i >= 0; i--) {
        a[i] = min(a[i], a[i + 1] + 1);
    }

    i64 ans = accumulate(b.begin(), b.end(), i64()) - accumulate(a.begin(), a.end(), i64());

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