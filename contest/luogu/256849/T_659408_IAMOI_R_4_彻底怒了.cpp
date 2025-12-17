#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

string a = "CDNL";

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;

    vector<int> f(n + 1), g(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + (s.substr(i, 4) == a);
        g[i + 1] = g[i] + (t.substr(i, 4) == a);
    }

    auto safeSum = [&](vector<int> &pre, int l, int r) {
        l = max(l, 0);
        r = min(r, n);
        if (r <= l) {
            return 0;
        }
        return pre[r] - pre[l];
    };

    int p[3]{};

    for (int j = 0; j < 3; j++) {
        string tar = a.substr(4 - j - 1);
        for (int i = 0; i < n; i++) {
            if (t.substr(i, j + 1) == tar) {
                p[j] = max(p[j], safeSum(g, i, i + k - 3));
            }
        }
    }

    int ori = 0;
    for (int i = 0; i < n; i++) {
        ori = max(ori, safeSum(g, i, i + k - 3));
    }
    int ans = ori;
    for (int i = 0; i + m <= n; i++) {
        ans = max(ans, ori + safeSum(f, i, i + m - 3));
    }
    for (int j = 0; j < 3; j++) {
        string tar = a.substr(0, j + 1);

        for (int i = j + 1; i <= n; i++) {
            if (s.substr(i - j - 1, j + 1) == tar) {
                ans = max(ans, p[2 - j] + safeSum(f, i - m, i - 3) + 1);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}