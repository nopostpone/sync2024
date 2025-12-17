#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a);

    vector<bool> vis(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (vis[i] or (i != 0 and a[i] == a[i - 1])) {
            continue;
        }

        bool ok = true;
        for (int y = a[i]; y <= k; y += a[i]) {
            int p = lower_bound(a.begin(), a.end(), y) - a.begin();
            if (p == n or a[p] != y) {
                ok = false;
            } else {
                vis[p] = true;
            }
        }
        if (not ok) {
            cout << -1 << "\n";
            return;
        }

        b.push_back(a[i]);
    }
    
    cout << b.size() << "\n";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " \n"[i + 1 == b.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
