#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

// ref : jiangly

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;

        a[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
        reverse(a[i].begin(), a[i].end());

        vector<int> na;
        for (auto x : a[i]) {
            if (find(na.begin(), na.end(), x) == na.end()) {
                na.push_back(x);
            }
        }
        a[i] = move(na);
    }
    vector<bool> vis(n);
    for (int _ = 0; _ < n; _++) {
        int p = -1;
        for (int i = 0; i < n; i++) {
            if (not vis[i] and (p == -1 or a[i] < a[p])) {
                p = i;
            }
        }
        vis[p] = true;
        for (auto x : a[p]) {
            cout << x + 1 << " ";
            for (int i = 0; i < n; i++) {
                if (not vis[i]) {
                    auto it = find(a[i].begin(), a[i].end(), x);
                    if (it != a[i].end()) {
                        a[i].erase(it);
                    }
                }
            }
        }
    }
    cout << "\n";
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