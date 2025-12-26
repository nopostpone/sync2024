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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](double x) {
        vector<double> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i] - x;
        }
        
        vector<double> lis;
        for (int i = 0; i < n; i++) {
            if (pre[i] < 0) {
                continue;
            }

            auto it = lower_bound(lis.begin(), lis.end(), pre[i]);
            if (it == lis.end()) {
                lis.push_back(pre[i]);
            } else {
                *it = pre[i];
            }
        }
        int p = lower_bound(lis.begin(), lis.end(), pre[n]) - lis.begin();
        return p >= k;
    };
    
    double lo = 0, hi = ranges::max(a);
    for (int t = 0; t < 25; t++) {
        double x = midpoint(lo, hi);
        if (check(x)) {
            lo = x;
        } else {
            hi = x;
        }
    }

    cout << fixed << setprecision(10) << lo << "\n";

    return 0;
}