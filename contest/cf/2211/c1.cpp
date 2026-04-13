#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            b[i]--;
        }
    }

    bool ok = true;
    for (int i = k; i < n; i++) {
        if (b[i] != -1 and a[i] != b[i]) {
            ok = false;
        }
    }
    for (int i = 0; i + k < n; i++) {
        if (b[i] != -1 and a[i] != b[i]) {
            ok = false;
        }
    }
    vector<int> vis(n);
    int fix = 0;
    for (int i = n - k; i < k; i++) {
        vis[a[i]]++;
        if (b[i] != -1) {
            vis[b[i]]--;
        } else {
            fix++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] < 0) {
            ok = false;
        }
        if (vis[i] > 0) {
            fix--;
        }
    }

    ok &= (fix == 0);
    cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}