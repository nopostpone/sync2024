#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int query(int t, int l, int r) {
    cout << t << " " << l + 1 << " " << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;

    int ori = n * (n + 1) / 2;
    int cur = query(2, 0, n);

    int len = cur - ori;
    int lo = 1, hi = n + 1;
    while (lo < hi) {
        int x = (lo + hi) / 2;
        if (query(1, 0, x) != query(2, 0, x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    cout << "! " << lo << " " << lo + len - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}