#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<array<int, 30>> p(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            p[i][j] = (a[i] >> j & 1);
        }
        for (int j = 1; j < 30; j++) {
            p[i][j] ^= p[i][j - 1];
        }
    }

    i64 ans = 0;
    for (int d = 0; d < 30; d++) {
        i64 cnt[2][2]{};
        for (int i = 0; i < n; i++) {
            int t1 = (a[i] >> d & 1);
            int t2 = p[i][d];
            cnt[t1][t2]++;
        }
        i64 res = cnt[0][1] * cnt[1][0] + cnt[1][1] * cnt[0][0];
        ans += res << d;
    }

    cout << ans << "\n";

    return 0;
}