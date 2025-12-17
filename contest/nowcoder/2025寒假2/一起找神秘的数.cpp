#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll l, r;
    cin >> l >> r;

    cout << (r - l + 1) << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}