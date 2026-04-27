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

    vector<int> p(n), v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> v[i] >> w[i];
    }
    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return v[i] < v[j];
    });

    vector<double> f(m + 1);
    for (auto i : ord) {
        double x = (double)p[i] / 100;
        for (int j = m; j - w[i] >= 0; j--) {
            f[j] = max(f[j], f[j - w[i]] * (1 - x) + x * v[i]);
        }
    }

    cout << fixed << setprecision(10) << ranges::max(f) << "\n";
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