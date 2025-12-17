#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, [&](int i, int j) {
        return b[i] > b[j];
    });

    ll B{}, A{};
    for (auto i : id) {
        B += max(0, b[i] - a[i]);
    }
    ll ans{};
    if (k == 0) {
        ans = max(ans, B - A);
    }

    priority_queue<int> q;
    for (auto i : id) {
        q.push(a[i]);
        A += a[i];
        B -= max(0, b[i] - a[i]);

        if (q.size() > k) {
            A -= q.top();
            q.pop();
        }
        if (q.size() == k) {
            ans = max(ans, B - A);
        }
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