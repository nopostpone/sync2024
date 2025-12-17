#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    vector<int> a;
    for (int x; cin >> x;) {
        a.push_back(x);
    }

    const int n = a.size();

    vector<int> f(n + 1);
    f[0] = inf;

    int ans{};
    for (int x : a) {
        int lo = 0, hi = n + 1;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (f[m] < x) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        ans = max(ans, lo);
        f[lo] = x;
    }
    cout << ans << "\n";

    set<int> s;
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(a[i]);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(a[i]);
    }
    cout << s.size() << "\n";

    return 0;
}