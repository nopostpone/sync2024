#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]]++;
    }

    int mex = 0;
    while (mex < n and c[mex] != 0) {
        mex++;
    }
    int p = 0;
    while (p < mex and c[p] == 1) {
        p++;
    }

    if (k == 1) {
        i64 ans = 0;
        for (auto x : a) {
            if (x > mex) {
                ans += mex;
            } else if (c[x] > 1) {
                ans += mex;
            } else {
                ans += x;
            }
        }
        cout << ans << "\n";
        return;
    }
    k--;

    i64 ans = 0, cnt = 0;
    for (auto x : a) {
        if (x < p) {
            ans += x;
        } else {
            cnt++;
        }
    }

    if (cnt == 1) {
        ans += mex;
        cout << ans << "\n";
        return;
    }

    i64 t = 0;
    if ((k % 2 == 0) ^ (p != mex)) {
        t = p;
    } else {
        t = p + 1;
    }

    ans += t * cnt;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}