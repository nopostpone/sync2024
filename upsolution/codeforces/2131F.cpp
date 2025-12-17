#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + (b[i] == '1');
    }
    vector<tuple<int, int, int>> e;
    for (int r = 1; r <= n; r++) {
        e.emplace_back(f[r] - r + f[r], f[r], r - f[r]);
    }
    ranges::sort(e);

    vector<i64> pre0(n + 1), pre1(n + 1);
    for (int i = 0; i < n; i++) {
        auto [_, c1, c0] = e[i];
        pre0[i + 1] = pre0[i] + c0;
        pre1[i + 1] = pre1[i] + c1;
    }

    i64 ans = 0;
    array<int, 2> c{};
    for (int i = 0; i < n; i++) {
        c[a[i] - '0']++;
        int d = c[0] - c[1];

        int p = lower_bound(e.begin(), e.end(), tuple(d, 0, 0)) - e.begin();
        ans += pre0[n] - pre0[p] + (i64)c[0] * (n - p);
        ans += pre1[p] + (i64)c[1] * p;
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