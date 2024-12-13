#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 维护区间典

void solve() {
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    vector<int> R(n, -1);
    {
        ranges::sort(p, [&](int x, int y) {
            if (l[x] == l[y]) {
                return r[x] > r[y];
            }
            return l[x] < l[y];
        });
        set<int> s;
        for (int j = 0; j < n; j++) {
            int i = p[j];
            auto it = s.lower_bound(r[i]);
            if (it != s.end()) {
                R[i] = *it;
            }
            s.insert(r[i]);
            if (j + 1 < n and l[i] == l[p[j + 1]] and r[i] == r[p[j + 1]]) {
                R[i] = r[i];
            }
        }
    }

    vector<int> L(n, -1);
    {
        ranges::sort(p, [&](int x, int y) {
            if (r[x] == r[y]) {
                return l[x] < l[y];
            }
            return r[x] > r[y];
        });
        set<int> s;
        for (int j = 0; j < n; j++) {
            int i = p[j];
            auto it = s.upper_bound(l[i]);
            if (it != s.begin()) {
                L[i] = *prev(it);
            }
            s.insert(l[i]);
            if (j + 1 < n and l[i] == l[p[j + 1]] and r[i] == r[p[j + 1]]) {
                L[i] = l[i];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        int ans{};
        if (L[i] != -1) {
            ans = R[i] - L[i] - (r[i] - l[i]);
        }
        cout << ans << "\n";
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