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
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<pair<int, int>, int> f;
    for (int i = 0; i < n; i++) {
        f[make_pair(a[i], b[i])] = i;
    }
    bool ok = true;
    int same = 0;
    for (const auto &[p, _] : f) {
        if (p.first == p.second) {
            same++;
            continue;
        }
        auto q = make_pair(p.second, p.first);
        if (not f.contains(q)) {
            ok = false;
        }
    }
    if (same > (n % 2)) {
        ok = false;
    }
    if (not ok) {
        cout << -1 << "\n";
        return;
    }

    vector<array<int, 2>> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] and i != n / 2) {
            int ni = n / 2;
            auto p = make_pair(a[i], b[i]);
            auto q = make_pair(a[ni], b[ni]);
            swap(a[i], a[ni]);
            swap(b[i], b[ni]);
            f[p] = ni;
            f[q] = i;
            ans.push_back({i, ni});
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        }
        auto p = make_pair(a[i], b[i]);
        auto q = make_pair(b[i], a[i]);
        int j = f[q];
        if (i + j != n - 1) {
            int nj = n - 1 - i;
            auto r = make_pair(a[nj], b[nj]);
            swap(a[j], a[nj]);
            swap(b[j], b[nj]);
            f[q] = nj;
            f[r] = j;
            ans.push_back({j, nj});
        }
    }
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
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