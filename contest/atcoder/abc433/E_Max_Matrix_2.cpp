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

    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
        y[i]--;
    }

    vector<int> px(n * m, -1), py(n * m, -1);
    for (int i = 0; i < n; i++) {
        if (px[x[i]] != -1) {
            cout << "No\n";
            return;
        }
        px[x[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        if (py[y[i]] != -1) {
            cout << "No\n";
            return;
        }
        py[y[i]] = i;
    }

    vector<vector<pair<int, int>>> vec(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vec[min(x[i], y[j])].emplace_back(i, j);
        }
    }

    vector<pair<int, int>> cand;
    auto fold = [&](int v) {
        for (auto p : vec[v]) {
            cand.push_back(move(p));
        }
    };

    vector ans(n, vector<int>(m, -1));
    
    for (int v = n * m - 1; v >= 0; v--) {
        int i = px[v];
        int j = py[v];

        if (i == -1 and j == -1) {
            do {
                if (cand.empty()) {
                    cout << "No\n";
                    return;
                }
                tie(i, j) = cand.back();
                cand.pop_back();
            } while (ans[i][j] != -1);
        } else if (i == -1 or j == -1) {
            if (vec[v].empty()) {
                cout << "No\n";
                return;
            }
            tie(i, j) = vec[v].back();
            vec[v].pop_back();
        }

        ans[i][j] = v;
        fold(v);
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] + 1 << " \n"[j == m - 1];
        }
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

    return 0;
}