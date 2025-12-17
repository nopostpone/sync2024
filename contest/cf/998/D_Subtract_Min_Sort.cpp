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

    for (int i = 1; i < n; i++) {
        int t = min(a[i], a[i - 1]);
        a[i] -= t;
        a[i - 1] -= t;
    }    
    bool ok{true};
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
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