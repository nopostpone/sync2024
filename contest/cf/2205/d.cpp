#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

// ref : jiangly

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> l(n, -1), r(n, n);

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (not stk.empty() and a[i] > a[stk.back()]) {
            r[stk.back()] = i;
            stk.pop_back();
        }
        if (not stk.empty()) {
            l[i] = stk.back();
        }
        stk.push_back(i);
    }

    vector<int> fl(n), fr(n);
    for (int i = 0; i < n; i++) {
        if (l[i] != -1) {
            fl[i] = fl[l[i]] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (r[i] != n) {
            fr[i] = fr[r[i]] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, fl[i] + 1 + fr[i]);
    }
    cout << n - ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}