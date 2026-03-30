#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    array<int, 10> cnt {};
    for (auto c : s) {
        cnt[c - '0']++;
    }

    auto check = [&](int m) {
        for (int i = 0; i <= m; i++) {
            int a = cnt[0] - (m - i);
            int b = cnt[1] - 2 * i;
            int c = accumulate(cnt.begin() + 2, cnt.begin() + 6, 0);
            int d = accumulate(cnt.begin() + 6, cnt.end(), 0);

            if (a >= 0 and b >= 0 and a + b + c >= m and a + b + c + d >= 2 * m - i) {
                return true;
            }
        }
        return false;
    };

    int lo = 0, hi = n / 4;
    while (lo < hi) {
        int x = midpoint(lo, hi + 1);
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }

    cout << lo << "\n";
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