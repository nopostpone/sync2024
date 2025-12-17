#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

using f64 = long double;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<pair<f64, i64>> q;
    for (int i = 0; i < n; i++) {
        q.emplace(a[i], 1);
    }
    while (k > 0) {
        auto [v, cnt] = q.top();
        q.pop();

        if (k >= cnt) {
            k -= cnt;
            q.emplace(v / 2, cnt * 2);
        } else {
            q.emplace(v, cnt - k);
            q.emplace(v / 2, k * 2);
            break;
        }
    }
    f64 ans = 0;
    while (true) {
        auto [v, cnt] = q.top();
        q.pop();

        if (x > cnt) {
            x -= cnt;
        } else {
            ans = v;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}