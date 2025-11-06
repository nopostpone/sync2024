#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }

    vector<int> suf(n);
    for (int i = n - 1; i; i--) {
        suf[i - 1] = suf[i] + a[i];
    }

    ranges::sort(suf, greater<>());
    ll ans{};
    for (int i = 0; i < n; i++) {
        ans += suf[i];
        if (ans >= k) {
            cout << i + 2 << "\n";
            return;   
        }
    }
    cout << -1 << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}