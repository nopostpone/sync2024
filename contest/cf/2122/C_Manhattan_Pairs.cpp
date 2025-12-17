#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n), u(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        u[i] = x[i] + y[i];
        v[i] = x[i] - y[i];
    }
    vector<int> p(n);
    ranges::iota(p, 0);

    ranges::sort(p, [&](int i, int j) {
        return x[i] < x[j];
    });
    sort(p.begin(), p.begin() + n / 2, [&](int i, int j) {
        return y[i] < y[j];
    });
    sort(p.begin() + n / 2, p.end(), [&](int i, int j) {
        return y[i] < y[j];
    });
    
    for (int i = 0; i < n / 2; i++) {
        cout << p[i] + 1 << " " << p[n - i - 1] + 1 << "\n";
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