#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 2>> a(n);
    for (int j : {0, 1}) {
        for (int i = 0; i < n; i++) {
            cin >> a[i][j];
        }
    }
    ranges::sort(a);

    priority_queue<ll> q;

    ll bsum = 0;
    for (int i = 0; i < k; i++) {
        q.push(a[i][1]);
        bsum += a[i][1];
    }

    ll ans = bsum * a[k - 1].front();
    for (int i = k; i < n; i++) {
        bsum -= q.top();
        q.pop();

        q.push(a[i].back());
        bsum += a[i].back();
        ans = min(ans, bsum * a[i].front());
    }
    cout << ans << "\n";

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}