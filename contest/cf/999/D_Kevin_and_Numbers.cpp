#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    map<int, int> f;
    for (auto x : a) {
        f[x]++;
    }
    ranges::sort(b);

    auto Find = [&](auto &&self, int x) -> bool {
        if (f.contains(x)) {
            f[x]--;
            if (f[x] <= 0) {
                f.erase(x);
            }
            return true;
        } else if (f.empty() or f.begin()->first > x) {
            return false;
        }
        if (x % 2 == 0) {
            return self(self, x / 2) and self(self, x / 2);
        } else {
            return self(self, x / 2) and self(self, x / 2 + 1);
        }
    };

    bool ok = true;
    for (auto x : b) {
        ok &= Find(Find, x);
    }
    ok &= f.empty();
    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}