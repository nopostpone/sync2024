#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    array<int, 3> a;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    int x = a[0] + a[1] + a[2];

    int m = n / x;
    n %= x;

    int ans{3 * m};
    if (n == 0) {

    } else if (n <= a[0]) {
        ans++;
    } else if (n <= a[0] + a[1]) {
        ans += 2;
    } else {
        ans += 3;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}