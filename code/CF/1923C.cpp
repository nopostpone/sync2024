#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pre(n + 1), s(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i] - 1;
        s[i + 1] = s[i] + (a[i] == 1);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << (l != r and s[r] - s[l - 1] <= pre[r] - pre[l - 1] ? "YES" : "NO") << "\n";
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