#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int lpos = 1, rpos = 1;
    int ans = 0;

    while (lpos <= n and rpos <= n) {
        ll sum = pre[rpos] - pre[lpos - 1];
        if (sum < l) {
            rpos++;
        } else if (sum > r) {
            if (lpos == rpos) {
                lpos++, rpos++;
            } else {
                lpos++;
            }
        } else {
            lpos = rpos + 1;
            rpos = lpos;
            ans++;
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