#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto oa = a;

    ranges::sort(a);
    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<double> dp(k + 1);
    const double C = (double)n * (n - 1) / 2;

    dp[0] = (double)pre[n] * (n - 1) / C;

    for (int i = 0; i < k; i++) {
        i64 sum = 0;
        i64 cnt = 0;

        int l = 0, r = n;
        while (l + 1 < r) {
            while (l + 1 < r and a[l] + a[r - 1] > dp[i]) {
                r--;
            }
            if (l + 1 >= r) {
                break;
            }
            cnt += r - (l + 1);
            sum += pre[n] - pre[r] + (i64)(n - r) * a[l];
            l++;
        }
        sum += (pre[n] - pre[l]) * (n - l - 1);
        dp[i + 1] = (dp[i] * cnt + sum) / C;
    }

    cout << fixed << setprecision(15) << dp[k] << "\n";

    constexpr double e = 1e-4;

    for (int i = 0; i < q; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;

        if (c == 0) {
            cout << "accept\n";
            continue;
        }
        double cur = oa[x] + oa[y];
        double opt = dp[c - 1];

        if (abs(cur - opt) <= e) {
            cout << "both\n";
        } else if (cur > opt) {
            cout << "accept\n";
        } else {
            cout << "reselect\n";
        }
    }

    return 0;
}