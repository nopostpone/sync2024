#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k;
    cin >> T >> k;

    constexpr auto digit = [](i64 x) {
        int ans = 0;
        while (x) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    };

    // int n = 2e6;
    // unordered_map<i64, int> cnt;
    // for (int i = 1; i <= n; i++) {
    //     int x = i;
    //     i64 sum = x;
    //     for (int j = 0; j < k; j++) {
    //         if (x < 10) {
    //             sum += x * (k - j);
    //             break;     
    //         }
    //         x = digit(x);
    //         sum += x;
    //     }
    //     cnt[sum]++;
    // }

    while (T--) {
        i64 m;
        cin >> m;

        if (k == 0) {
            cout << 1 << "\n";
            continue;
        } else if (k == 1) {
            int ans = 0;
            for (int x = 1; x <= 18 * 9; x++) {
                i64 ori = m - x;
                if (ori < 0) {
                    continue;
                }
                ans += x == digit(ori);
            }
            cout << ans << "\n";
        } else {
            int ans = 0;

            for (int d = 1; d <= 9; d++) {
                for (int x = 1; x <= 18 * 9; x++) {
                    if (digit(x) != d) {
                        continue;
                    }
                    i64 ori = m - x - 1ll * d * (k - 1);
                    if (ori > 0 and digit(ori) == x) {
                        ans++;
                    }
                }
            }

            for (int d = 1; d <= 9; d++) {
                for (int x = 10; x <= 9 * 2; x++) {
                    if (digit(x) != d) {
                        continue;
                    }
                    for (int y = 1; y <= 18 * 9; y++) {
                        if (digit(y) != x) {
                            continue;
                        }
                        i64 ori = m - x - y - 1ll * d * (k - 2);
                        if (ori > 0 and digit(ori) == y) {
                            ans++;
                        }
                    }
                }
            }
            

            cout << ans << "\n";
        }
    }

    return 0;
}