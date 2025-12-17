#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int maxa = ranges::max(a);

    vector<int> c(maxa + 1);
    vector<i64> s(maxa + 1);

    for (auto x : a) {
        c[x]++;
        s[x] += x;
    }
    for (int i = 0; i < maxa; i++) {
        c[i + 1] += c[i];
        s[i + 1] += s[i];
    }
    const i64 S = s.back() + k;

    auto check = [&](i64 x) {
        i64 cnt = 0;
        if (x >= maxa) {
            cnt = n * x - s.back();
        } else {
            for (int i = x; i - x < maxa; i += x) {
                cnt += (i64)i * (c[min(i, maxa)] - c[i - x]) - (s[min(i, maxa)] - s[i - x]);
            }
        }

        return cnt <= k and (k - cnt) % x == 0;
    };

    i64 ans = 0;
    for (i64 i = 1; i * i <= S; i++) {
        if (S % i == 0) {
            if (check(i)) {
                ans = max(ans, i);
            }
            if (check(S / i)) {
                ans = max(ans, S / i);
            }
        }
    }
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
