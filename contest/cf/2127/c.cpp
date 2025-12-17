#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n, _;
    cin >> n >> _;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    i64 ori = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ori += std::abs(a[i] - b[i]);
    }

    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return a[i] < a[j] or (a[i] == a[j] and b[i] < b[j]);
    });

    i64 ans = inf;
    for (int i = 1; i < n; i++) {
        int l1 = min(a[ord[i - 1]], b[ord[i - 1]]);
        int r1 = max(a[ord[i - 1]], b[ord[i - 1]]);
        int l2 = min(a[ord[i]], b[ord[i]]);
        int r2 = max(a[ord[i]], b[ord[i]]);

        ans = min(ans, ori - (r1 - l1) - (r2 - l2) + (r2 - l1) + std::abs(r1 - l2));
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