#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k < abs(n - m) or k > max(n, m)) {
        cout << -1 << "\n";
        return;
    }
    vector<int> a;
    a.reserve(n + m);

    int u = n;
    int v = m;

    if (n > m) {
        for (int i = 0; i < k; i++) {
            a.push_back(0);
        }
        u -= k;
        for (int i = 0; i < n + m - k; i++) {
            if (u == 0) {
                a.push_back(1);
            } else {
                if (i % 2) {
                    a.push_back(0);
                    u--;
                } else {
                    a.push_back(1);
                }
            }
        }
    } else {
        for (int i = 0; i < k; i++) {
            a.push_back(1);
        }
        v -= k;
        for (int i = 0; i < n + m - k; i++) {
            if (v == 0) {
                a.push_back(0);
            } else {
                if (i % 2) {
                    a.push_back(1);
                    v--;
                } else {
                    a.push_back(0);
                }
            }
        }
    }

    // for (auto x : a) {
    //     cerr << x;
    // }
    // cerr << endl;
    assert(count(a.begin(), a.end(), 1) == m and count(a.begin(), a.end(), 0) == n);

    for (int i = 0; i < n + m; i++) {
        cout << a[i];
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}