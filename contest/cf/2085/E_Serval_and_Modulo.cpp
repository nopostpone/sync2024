#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ranges::sort(a);
    ranges::sort(b);

    if (a == b) {
        cout << inf << "\n";
        return;
    }

    const i64 suma = accumulate(a.begin(), a.end(), 0ll);
    const i64 sumb = accumulate(b.begin(), b.end(), 0ll);

    const i64 dif = suma - sumb;

    int ans = -1;
    auto check = [&](int k) {
        if (k > inf) {
            return;
        }
        auto na = a;
        for (auto &x : na) {
            x %= k;
        }
        ranges::sort(na);
        if (na == b) {
            ans = k;
        }
    };

    for (i64 i = 1; i * i <= dif and ans == -1; i++) {
        if (dif % i != 0) {
            continue;
        }
        check(i);
        check(dif / i);
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
