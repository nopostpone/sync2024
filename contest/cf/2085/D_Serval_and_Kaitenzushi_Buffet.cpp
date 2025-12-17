#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    priority_queue<int> q;

    i64 ans = 0;

    int cnt = n / (k + 1);
    for (int i = 0, cur = cnt * (k + 1) - 1; i < n; i++) {
        q.push(d[i]);
        if (i == n - cur - 1) {
            ans += q.top();
            q.pop();
            cur -= k + 1;
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