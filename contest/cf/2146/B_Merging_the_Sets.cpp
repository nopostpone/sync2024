#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> s(m);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;

        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;
            x--;
            s[x].push_back(i);
        }
    }

    vector<bool> good(n);
    for (int x = 0; x < m; x++) {
        if (s[x].size() == 1) {
            int i = s[x].front();
            good[i] = true;
        } else if (s[x].empty()) {
            cout << "NO\n";
            return;
        }
    }

    if (ranges::count(good, false) >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}