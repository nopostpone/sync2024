#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](i64 x) {
        vector<int> need(n);

        i64 cur = 0;
        priority_queue<int> q1;
        for (int i = 0; i < n; i++) {
            q1.push(a[i]);
            cur += a[i];
            while (not q1.empty() and cur > x) {
                cur -= q1.top();
                q1.pop();
            }
            need[i] = q1.size();
        }

        cur = 0;

        priority_queue<int> q2;
        for (int i = n - 1; i >= 0; i--) {
            q2.push(a[i]);
            cur += a[i];
            while (not q2.empty() and cur > x) {
                cur -= q2.top();
                q2.pop();
            }
            if (q2.size() + (i ? need[i - 1] : 0) >= k) {
                return true;
            }
        }
        return false;
    };

    i64 lo = 0, hi = accumulate(a.begin(), a.end(), 0ll) + 1;
    while (lo < hi) {
        i64 m = (lo + hi) / 2;
        if (check(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << lo << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}