#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    ranges::sort(b);

    int cur = -INT_MAX;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        int tem = INT_MAX;
        if (a[i] >= cur) {
            ok = true;
            tem = a[i];
        }
        auto it = lower_bound(b.begin(), b.end(), cur + a[i]);
        if (it != b.end()) {
            // cerr << *it << endl;
            ok = true;
            tem = min(tem, *it - a[i]);
        }
        if (not ok) {
            cout << "NO\n";
            return;
        }
        cur = tem;
        // cerr << cur << endl;
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}