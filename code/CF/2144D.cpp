#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, y;
    cin >> n >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int V = ranges::max(a);
    if (V == 1) {
        cout << n << "\n";
        return;
    }

    vector<int> cnt(V + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    vector<int> pre(V + 1);
    for (int i = 1; i <= V; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    i64 ans = -1e18;
    for (int x = 2; x <= V; x++) {
        i64 res = 0;
        for (int i = 0; i < V; i += x) {
            int j = min(i + x, V);
            int ncnt = pre[j] - pre[i];

            int nval = i / x + 1;
            res -= (i64)max(0, ncnt - cnt[nval]) * y;
            res += i64(nval) * ncnt;
        }
        ans = max(ans, res);
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
