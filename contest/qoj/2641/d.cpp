// ref : jiangly
#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int N = 7;

constexpr int num[] {
    0b1110111,
    0b0100100,
    0b1011101,
    0b1101101,
    0b0101110,
    0b1101011,
    0b1111011,
    0b0100101,
    0b1111111,
    0b1101111,
};

constexpr int dx[] {0, 1, 1, 3, 4, 4, 6};
constexpr int dy[] {1, 0, 3, 1, 0, 3, 1};

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> on(n), off(n); // 第 i 个位置哪些灯常亮哪些常暗
    {
        string s[N];
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < N; j++) {
                auto c = s[dx[j]][i * 5 + dy[j]];
                if (c == '1') {
                    on[i] |= 1 << j;
                }
                if (c == '0') {
                    off[i] |= 1 << j;
                }
            }
        }
    }

    // f [到第几个位置][翻新了几个灯][是否允许全空] 能显示的最多数字
    vector f(n + 1, vector(k + 1, array<int, 2> {-1, -1}));
    // g [到第几个位置][翻新了几个灯] 且显示最多数字的方案数
    vector g(n + 1, vector(k + 1, array<i64, 2> {}));
    // h [到第几个位置][翻新了几个灯] 的所有方案数
    vector h(g);

    f[0][0][1] = 0;
    g[0][0][1] = h[0][0][1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int e = 0; e < 2; e++) {
                if (f[i][j][e] == -1) {
                    continue;
                }
                for (int s = 0; s < (1 << N); s++) {
                    int nj = j + __builtin_popcount(s);
                    if (nj > k) {
                        continue;
                    }
                    // 对于翻新的集合 s，能正常显示的数字，与能正常显示且非前导零的数字
                    int cnt = 0, cntnz = 0;

                    for (int x = 0; x < 10; x++) {
                        // 不能有灯管满足：
                        // 原先常亮、不翻新、且显示 x 时是本应该暗的
                        // 原先常暗、不翻新、且显示 x 时是本应该亮的
                        if (not (on[i] & ~s & ~num[x]) and not (off[i] & ~s & num[x])) {
                            // 那么就更新 cnt 和 cntnz
                            cnt++;
                            if (x != 0 or i == n - 1) {
                                cntnz++;
                            }
                        }
                    }
                    
                    // 允许全空，仅当之前就允许全空，且这个位置常亮的数字全部翻新
                    int ne = e and not (on[i] & ~s);
                    // 作为之前显示的数字的后缀 + 作为第一个数位
                    int tf = f[i][j][e] * cnt + e * cntnz;
                    // 如果翻新集合 s 后，什么数字都不能显示
                    // 那么此时任何能到达 (i, j, e) 的方案，都能到达 (i + 1, nj, ne)
                    // 因为此时都只能显示 0 个数字
                    i64 tg = (tf != 0 ? g[i][j][e] : h[i][j][e]);
                    
                    // 从 (i, j, e) 转移到 (i + 1, nj, ne)
                    if (tf > f[i + 1][nj][ne]) {
                        f[i + 1][nj][ne] = tf;
                        g[i + 1][nj][ne] = tg;
                    } else if (tf == f[i + 1][nj][ne]) {
                        g[i + 1][nj][ne] += tg;
                    }
                    h[i + 1][nj][ne] += h[i][j][e];
                }
            }
        }
    }

    int ans = max(f[n][k][0], f[n][k][1]);
    i64 ways = 0;
    for (int j = 0; j <= k; j++) {
        for (int e = 0; e < 2; e++) {
            if (f[n][j][e] == ans) {
                ways += g[n][j][e];
            }
        }
    }
    cout << ans << " " << ways << "\n";
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