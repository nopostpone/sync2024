#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    array<int, 3> a;
    i64 m;
    cin >> a[0] >> a[1] >> a[2] >> m;

    array<i64, 8> f {};
    for (int s = 1; s < 8; s++) {
        i64 l = 1;
        for (int i = 0; i < 3; i++) {
            if (s >> i & 1) {
                l = std::lcm(l, a[i]);
            }
        }
        assert(l != 0);
        f[s] = m / l;
    }

    // auto g = f;

    array<i64, 3> ans {};
    for (int i = 0; i < 3; i++) {
        for (int s = 0; s < 8; s++) {
            if (s >> i & 1) {
                f[s ^ (1 << i)] -= f[s];
            }
        }
    }
    for (int s = 0; s < 8; s++) {
        int cnt = __builtin_popcount(s);
        if (cnt == 1) {
            ans[__lg(s)] += f[s] * 6;
        } else if (cnt == 2) {
            for (int i = 0; i < 3; i++) {
                if (s >> i & 1) {
                    ans[i] += f[s] * 3;
                }
            }
        } else if (cnt == 3) {
            for (int i = 0; i < 3; i++) {
                ans[i] += f[s] * 2;
            }
        }
    }

    // cerr << g[3] << " " << g[6] << " " << g[5] << "\n";
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << " \n"[i == 2];
    }
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