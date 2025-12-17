#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok{1};
    for (int i = 1; i < n; i++) {
        int d = abs(a[i] - a[i - 1]);
        if (d != 5 and d != 7) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}