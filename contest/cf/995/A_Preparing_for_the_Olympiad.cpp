#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    int m{a[n - 1]}, s{};
    for (int i = 0; i < n - 1; i++) {
        if (a[i] - b[i + 1] > 0) {
            m += a[i];
            s += b[i + 1];
        }
    }

    cout << m - s << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}