#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    constexpr int L = 30;
    vector f(L + 1, vector<int>(n));
    vector g(L + 1, vector<i64>(n));

    for (int i = 0; i < n; i++) {
        f[0][i] = a[i];
        g[0][i] = i + 1;
    }
    for (int j = 0; j < L; j++) {
        for (int i = 0; i < n; i++) {
            f[j + 1][i] = f[j][f[j][i]];
            g[j + 1][i] = g[j][f[j][i]] + g[j][i];
        }
    }

    for (int _ = 0; _ < q; _++) {
        int t, b;
        cin >> t >> b;
        b--;

        i64 ans = 0;
        for (int i = 0; i < L; i++) {
            if (t >> i & 1) {
                ans += g[i][b];
                b = f[i][b];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}