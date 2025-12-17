#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; i++) {
        d1[i] = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
    }
    set<int> c;
    for (int i = 1; i < n; i++) {
        if (a[i] > b[i - 1]) {
            c.insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        auto it = c.upper_bound(i);
        if (it == c.end()) {
            d2[i] = b.back() - a[i];
        } else {
            int x = *it;
            d2[i] = b[x - 1] - a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << d1[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << d2[i] << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}