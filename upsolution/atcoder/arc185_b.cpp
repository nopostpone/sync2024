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
    const ll sum = std::accumulate(a.begin(), a.end(), 0ll);
    const int base = sum / n;
    const int mod = sum % n;

    vector<int> b(n, base);
    for (int i = n - mod; i < n; i++) {
        b[i]++;
    }
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + b[i] - a[i];
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (pre[i] < 0) {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}