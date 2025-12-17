#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> f;
    for (auto i : a) {
        f[i]++;
    }
    multiset<int> s;
    for (auto [x, y] : f) {
        s.insert(y);
    }

    int ans = f.size();
    for (auto x : s) {
        if (k >= x and ans != 1) {
            k -= x;
            ans--;
        } else {
            break;
        }
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}