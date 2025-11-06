#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum ColorCompare {
    same,
    diff,
    part,
};

ColorCompare check(const string &L, const string &R) {
    if (L == R) {
        return same;
    }
    for (auto i : L) {
        if (R.find(i) != string::npos) {
            return part;
        }
    }
    return diff;
}

map<string, int> f;
vector<string> g;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<string> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> L(n, -1e8), R(n, 1e8);
    for (int i = 0; i < n; i++) {
        for (auto color : g) {
            if (check(color, c[i]) == part and f.contains(color)) {
                L[i] = max(L[i], f[color]);
            }
        }
        f[c[i]] = i;
    }
    f.clear();
    for (int i = n - 1; ~i; i--) {
        for (auto color : g) {
            if (check(color, c[i]) == part and f.contains(color)) {
                R[i] = min(R[i], f[color]);
            }
        }
        f[c[i]] = i;
    }
    f.clear();

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (r < l) {
            swap(l, r);
        }

        if (check(c[l], c[r]) != diff) {
            cout << r - l << "\n";
        } else if (L[l] != -1e8 or R[l] != 1e8) {
            cout << min({l - L[l] + r - L[l],
                         R[l] - l + std::abs(r - R[l]),
                         R[r] - r + R[r] - l,
                         r - L[r] + std::abs(L[r] - l)}) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    g = {"BG", "BR", "BY", "GR", "GY", "RY"};

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}