#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, p, q;
    cin >> n >> p >> q;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return x[i] < x[j] or (x[i] == x[j] and y[i] > y[j]);
    });

    i64 ans = i64(p) * (p + 1) / 2 * (q + 1) + i64(q) * (q + 1) / 2 * (p + 1);

    vector<int> lis;
    int pos = 0;

    i64 sum = 0;
    for (auto i : ord) {
        if (x[i] >= p or y[i] >= q) {
            continue;
        }

        ans -= sum * (x[i] - pos);

        auto it = lower_bound(lis.begin(), lis.end(), y[i]);

        if (it == lis.end()) {
            lis.push_back(y[i]);
        } else {
            sum -= (q - *it);
            *it = y[i];
        }
        sum += (q - y[i]);

        pos = x[i];
    }
    ans -= sum * (p - pos);

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