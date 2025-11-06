#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    ll now = 0;
    map<ll, int> f;

    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            f[-now]++;
        } else if (op == 2) {
            int t;
            cin >> t;
            now += t;
        } else {
            ll h;
            cin >> h;
            auto it = f.lower_bound(h - now);
            int ans = 0;
            for (auto i = it; i != f.end(); i++) {
                ans += i->second;
            }
            f.erase(it, f.end());
            cout << ans << "\n";
        }
    }

    return 0;
}