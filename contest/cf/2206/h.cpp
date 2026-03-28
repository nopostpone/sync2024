#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 0;

    int g = 0;
    for (int i = 1; i < n; i++) {
        g = std::gcd(g, std::abs(a[i] - a[0]));
        ans += std::abs(a[i] - a[i - 1]);
    }
    if (g == 0) {
        ans = a[0];
    } else {
        ans += ((a[0] - 1) % (2 * g)) + 1;
    }

    cout << ans << "\n";
}