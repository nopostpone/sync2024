#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

vector<int> build(int l, int r) {
    if (l > r) {
        return {};
    }
    if (l == r) {
        return {l};
    }

    int t = 1;
    while (t * 2 <= r) {
        t *= 2;
    }
    if (l >= t) {
        auto a = build(l - t, r - t);
        for (auto &x : a) {
            x += t;
        }
        return move(a);
    }

    int n = r - l + 1;
    vector<int> a(n, -1);

    int mx = min(r, 2 * t - 1 - l);
    for (int i = t; i <= mx; i++) {
        int j = 2 * t - 1 - i;
        a[i - l] = j;
        a[j - l] = i;
    }

    int nt = 2 * t - 2 - r;
    {
        auto b = build(l, nt);
        for (int i = 0; i < b.size(); i++) {
            a[i] = b[i];
        }
    }

    int s = mx + 1;
    {
        auto b = build(s, r);
        for (int i = 0; i < b.size(); i++) {
            a[s - l + i] = b[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = l + i;
        }
    }
    return move(a);
}

void solve() {
    int l, r;
    cin >> l >> r;

    auto a = build(l, r);

    i64 ans = 0;
    for (int i = 0; i <= r - l; i++) {
        ans += a[i] | (i + l);
    }
    cout << ans << "\n";

    for (int i = 0; i <= r - l; i++) {
        cout << a[i] << " \n"[i == r - l];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
