#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int p[] = {2, 3, 5, 7};

void solve() {
    i64 l, r;
    cin >> l >> r;

    auto work = [&](i64 n) {
        i64 ans = n;
        for (int s = 1; s < 16; s++) {
            int bad = 1;
            for (int i = 0; i < 4; i++) {
                if (s >> i & 1) {
                    bad *= p[i];
                }
            }
            int coef = (__builtin_popcount(s) & 1) ? -1 : 1;
            ans += coef * (n / bad);
        }
        return ans;
    };

    cout << work(r) - work(l - 1) << "\n";
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