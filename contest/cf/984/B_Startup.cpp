#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> f;
    for (int i = 0; i < k; i++) {
        int b, c;
        cin >> b >> c;
        f[b] += c;
    }
    priority_queue<int> q;
    for (auto [x, y] : f) {
        q.push(y);
    }
    ll ans{};
    for (int i = 0; i < n and not q.empty(); i++) {
        ans += q.top();
        q.pop();
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