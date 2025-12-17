#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ans.push_back(a[i - 1]);
            ans.push_back(a[i]);
            break;
        }
    }

    if (ans.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << 2 << "\n";
    for (int i = 0; i < 2; i++) {
        cout << ans[i] << " \n"[i == 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}