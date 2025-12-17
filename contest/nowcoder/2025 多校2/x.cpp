#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 7;
using B = bitset<N>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 ans = 0;
    for (int s = 0; s < 1 << N; s++) {
        B b(s);
        // cerr << b << " ";
        int x = 0;
        int y = 0;
        for (int i = 1; i < N; i++) {
            if (b[i] and b[i - 1] == 0) {
                x++;
            }
            if (b[i] == 0 and b[i - 1]) {
                y++;
            }
        }
        // cerr << res << endl;
        ans += min(x, y);
    }
    cout << ans << endl;

    // vector<int> f(11);
    // for (int i = 1; i <= 10; i++) {
    //     f[i] = (i + 2) * (1 << i - 1) + (1 << i);
    //     cerr << f[i] << endl;
    // }

    return 0;
}