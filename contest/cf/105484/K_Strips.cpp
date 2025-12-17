#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<pair<int, int>> e;
    e.reserve(n + m + 2);

    e.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        e.emplace_back(x, 1);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        e.emplace_back(x, 0);
    }
    e.emplace_back(w + 1, 0);

    ranges::sort(e);

    int L = 0;

    vector<int> ans;

    for (auto [x, t] : e) {
        if (t == 0) {
            if (not ans.empty()) {

                int R = x;
                for (int j = ans.size() - 1; j >= 0; j--) {
                    
                    int r = ans[j] + k;
                    if (r > R) {
                        int d = r - R;
                        ans[j] -= d;

                        if (ans[j] <= L) {
                            cout << -1 << "\n";
                            return;
                        }

                        R = ans[j];
                    } else {
                        break;
                    }
                }
            }

            L = x;
            continue;
        }

        if (ans.empty() or ans.back() + k - 1 < x) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " \n"[x == ans.back()];
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