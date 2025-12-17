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
    for (auto x : a) {
        f[x]++;
    }
    int ans{};
    for (auto [x, y] : f) {
        int t = k - x;
        if (t < x) {
            break;
        }
        if (t == x) {
            ans += y / 2;
        } else {
            if (f.find(t) != f.end()) {
                ans += min(y, f.find(t)->second);
            }
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