#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        vec[b].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if ((int)vec[i].size() % i != 0) {
            cout << -1 << "\n";
            return;
        }
    }

    int cur = 0;
    vector<int> ans(n, -1);
    for (int v = 1; v <= n; v++) {
        for (int i = 0; i < vec[v].size(); i++) {
            if (i % v == 0) {
                cur++;
            }
            ans[vec[v][i]] = cur;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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