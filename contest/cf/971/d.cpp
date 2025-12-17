#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    using pii = pair<int, int>;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector vis(n + 1, vector<bool>(2));
    for (auto [x, y] : a) {
        vis[x][y] = true;
    }

    sort(a.begin(), a.end());
    ll res = 0;

    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first) {
            res += n - 2;
        }
    }

    for (int i = 1; i < n; i++) {
        res += vis[i][0] and vis[i - 1][1] and vis[i + 1][1];
        res += vis[i][1] and vis[i - 1][0] and vis[i + 1][0];
    }
    cout << res << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}