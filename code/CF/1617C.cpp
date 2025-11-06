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

    set<int> S;
    for (int i = 1; i <= n; i++) {
        S.insert(i);
    }

    int res = 0;
    ranges::sort(a);
    for (auto i : a) {
        if (S.contains(i)) {
            S.erase(i);
            continue;
        }
        res++;
        int t = min(i / 2 - (i % 2 == 0), n);

        auto it = S.upper_bound(t);
        if (it == S.begin()) {
            break;
        }
        S.erase(--it);
    }

    cout << (S.empty() ? res : -1) << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}