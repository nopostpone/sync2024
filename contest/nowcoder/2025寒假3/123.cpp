#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto b = a;
    ranges::sort(b);
    for (auto &x : a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
    }

    vector<int> t(n, 1);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            t[i] = t[i - 1];
        } else {
            t[i] = -t[i - 1];
        }
    }
    vector<int> pre(n + 1);
    pre[0] = n;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + t[i];
    }
    vector<int> cnt(2 * n + 1), f(n);

    int dist = 0;

    i64 ans = 0;
    for (int r = 1, l = 0; r <= n; r++) {
        cnt[pre[r - 1]]++;
        dist += (f[a[r - l]]++ == 0);
        while (dist > 2) {
            cnt[pre[l]]--;
            dist -= 
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}