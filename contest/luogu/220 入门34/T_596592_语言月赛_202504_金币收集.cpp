#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
    for (auto &x : a) {
        is >> x;
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, m;
    cin >> n >> s >> m;
    s--;

    vector<int> o(m);
    for (int i = 0; i < m; i++) {
        cin >> o[i];
        o[i]--;
    }

    vector<vector<i64>> p(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t) {
            p[i].resize(t);
            // cin >> p[i];
            for (int j = 0; j < t; j++) {
                cin >> p[i][j];
            }
        }
    }

    i64 ans = 0;
    vector<int> vis(n);

    if (vis[s] < (int)p[s].size()) {
        ans += p[s][vis[s]];
    }
    vis[s] = 1;

    for (int i = 0; i < m; i++) {
        if (!o[i]) {
            s++;
        } else {
            s--;
        }
        if (s == n) {
            s = 0;
        }
        if (s == -1) {
            s = n - 1;
        }
        if (vis[s] >= (int)p[s].size()) {
            continue;
        }
        ans += p[s][vis[s]];
        vis[s]++;
    }
    cout << ans << endl;

    return 0;
}