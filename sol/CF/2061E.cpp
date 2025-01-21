#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = (1 << 30) - 1;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> f(1 << m, inf);
    for (int s = 0; s < (1 << m); s++) {
        for (int i = 0; i < m; i++) {
            if (s >> i & 1) {
                f[s] &= b[i];
            }
        }
    }

    vector<int> c;
    c.reserve(n * m);

    for (auto x : a) {
        vector<int> h(m + 1, inf);
        for (unsigned s = 0; s < (1 << m); s++) {
            int t = popcount(s);
            h[t] = min(h[t], x & f[s]);
        }
        for (int i = 0; i < m; i++) {
            c.push_back(h[i] - h[i + 1]);
        }
    }

    ranges::sort(c, greater());

    ll ans = accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0; i < k; i++) {
        ans -= c[i];
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