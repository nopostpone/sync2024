#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<pair<int, int>>> segs(2 * n + 1);
    for (int i = 0; i < n; i++) {
        segs[a[i]].emplace_back(b[i], i);
    }
    vector<int> ans;
    for (int l = 1; l <= 2 * n; l++) {
        if (segs[l].empty()) {
            continue;
        }
        auto [r, i] = ranges::max(segs[l]);
        ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
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
