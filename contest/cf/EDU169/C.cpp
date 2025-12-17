#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<>());

    ll res = 0;
    for (int i = 1; i < n; i += 2) {
        int d = a[i - 1] - a[i];
        if (k >= d) {
            k -= d;
            d = 0;
        } else {
            d -= k;
            k = 0;
        }
        res += 1ll * d;
    }
    if (n & 1) {
        res += 1ll * a.back();
    }
    cout << res << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}