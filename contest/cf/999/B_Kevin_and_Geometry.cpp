#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> f;
    for (auto x : a) {
        f[x]++;
    }
    int u{}, v{}, w{};
    bool ok = false;
    for (auto it = f.rbegin(); it != f.rend(); it++) {
        int &y = it->second;
        if (y >= 2) {
            it->second -= 2;
            v = it->first;
            ok = true;
            if (it->second == 0) {
                f.erase(it->first);
            }
            break;
        }
    }
    if (not ok) {
        cout << -1 << "\n";
        return;
    }
    int lst{-1};
    for (auto [x, y] : f) {
        if (y >= 2) {
            u = x;
            w = x;
            break;
        }
        if (lst != -1) {
            if (lst + 2 * v > x) {
                u = lst;
                w = x;
                break;
            }
        }
        lst = x;
    }
    ok &= u and v and w;
    if (ok) {
        cout << v << " " << v << " " << u << " " << w << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}