#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    using psi = pair<string, int>;
    vector<psi> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    auto calc = [&](int i, bool t) {
        for (auto [calc, val] : a) {
            if (calc == "AND") {
                t &= (val >> i) & 1;
            } else if (calc == "OR") {
                t |= (val >> i) & 1;
            } else {
                t ^= (val >> i) & 1;
            }
        }
        return t;
    };

    int v = 0, res = 0;

    for (int i = 30; ~i; i--) {
        int t0 = calc(i, 0);
        int t1 = calc(i, 1);
        if (t1 > t0 and v + (1 << i) <= m) {
            res += t1 << i;
            v += 1 << i;
        } else {
            res += t0 << i;
        }
    }
    cout << res;

    return 0;
}

