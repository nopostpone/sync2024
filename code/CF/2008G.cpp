#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    k--;

    int g = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g = std::gcd(g, x);
    }

    if (n == 1) {
        cout << k + (k >= g) << endl;
    } else if (1ll * (g - 1) * n <= k) {
        cout << n + k << endl;
    } else {
        cout << k / (g - 1) * g + k % (g - 1) + 1 << endl;
    }

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}