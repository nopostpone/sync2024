#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int mask[10] = {
    0b1111110,
    0b0000110,
    0b1011011,
    0b1001111,
    0b0100111,
    0b1101101,
    0b1111101,
    0b1000110,
    0b1111111,
    0b1101111,
};

constexpr int inf = 1e9;

i64 f[1 << 7];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i] |= mask[s[i][j] - '0'] << (7 * j);
        }
    }

    vector<int> b(n), p(n);
    ranges::iota(p, 0);

    int ans = inf;

    auto dfs = [&](auto &&self, int i, int cur) -> void {
        if (i < m - 1) {
            for (int s = 0; s < 1 << 7; s++) {
                self(self, i + 1, cur | s << (7 * i));
            }
            return;
        }

        for (int j = 0; j < n; j++) {
            b[j] = a[j] & cur;
        }
        ranges::sort(p, [&](int i, int j) {
            return b[i] < b[j];
        });

        i64 need = 0;
        for (int l = 0, r = 0; l < n; l = r) {
            while (r < n and b[p[l]] == b[p[r]]) {
                r++;
            }
            for (int j1 = l; j1 < r; j1++) {
                for (int j2 = l; j2 < j1; j2++) {
                    int x = s[p[j1]][i] - '0';
                    int y = s[p[j2]][i] - '0';
                    if (x == y) {
                        return;
                    }
                    if (x < y) {
                        swap(x, y);
                    }
                    
                    need |= i64(1) << (x * (x - 1) / 2 + y);
                }
            }
        }
        for (int s = 0; s < 1 << 7; s++) {
            if ((f[s] & need) == need) {
                ans = min(ans, __builtin_popcount(cur) + __builtin_popcount(s));
            }
        }
    };

    dfs(dfs, 0, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int s = 0; s < (1 << 7); s++) {
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < i; j++) {
                if ((mask[i] & s) != (mask[j] & s)) {
                    f[s] |= i64(1) << (i * (i - 1) / 2 + j);
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}