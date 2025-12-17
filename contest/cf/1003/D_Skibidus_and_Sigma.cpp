#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<i64> s1(n), s2(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s2[i] += 1ll * a[i][j] * (m - j);
            s1[i] += a[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    ranges::sort(p, [&](int i, int j) {
        return s1[i] > s1[j];
    });

    i64 ans = accumulate(s2.begin(), s2.end(), 0ll);

    int len = n - 1;
    for (auto i : p) {
        ans += s1[i] * len * m;
        len--;
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}