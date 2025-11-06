#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> d;
    for (int i = 1; i <= m / i; i++) {
        if (m % i == 0) {
            d.push_back(i);
        }
    }
    for (int i = d.size() - 1; i > 0; i--) {
        if (d[i] != m / d[i] and m % d[i] == 0) {
            d.push_back(m / d[i]);
        }
    }

    const int D = d.size();

    vector<int> c(D);
    for (int h = 0; h < D; h++) {
        for (int i = 1; i < n; i++) {
            if (a[i - 1] % d[h] > a[i] % d[h]) {
                c[h]++;
            }
        }
    }
    
    while (q--) {
        int o;
        cin >> o;

        if (o == 1) {
            int i, x;
            cin >> i >> x;
            i--;

            for (int h = 0; h < D; h++) {
                if (i > 0 and a[i - 1] % d[h] > a[i] % d[h]) {
                    c[h]--;
                }
                if (i + 1 < n and a[i] % d[h] > a[i + 1] % d[h]) {
                    c[h]--;
                }
            }

            a[i] = x;
            for (int h = 0; h < D; h++) {
                if (i > 0 and a[i - 1] % d[h] > a[i] % d[h]) {
                    c[h]++;
                }
                if (i + 1 < n and a[i] % d[h] > a[i + 1] % d[h]) {
                    c[h]++;
                }
            }
        } else {
            int k;
            cin >> k;

            int g = gcd(k, m);
            int h = lower_bound(d.begin(), d.end(), g) - d.begin();

            cout << (c[h] < m / d[h] ? "YES" : "NO") << "\n";
        }
    }
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
