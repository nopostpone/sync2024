#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n[2];
    cin >> n[0] >> n[1];

    vector<pair<int, int>> a[2] {};
    vector<tuple<int, short, short>> e; 
    
    int sumLen[2] {};
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n[j]; i++) {
            int x, y;
            cin >> x >> y;
            a[j].emplace_back(x, y);
            sumLen[j] += y - x;
            e.emplace_back(x, j, 1);
            e.emplace_back(y, j, -1);
        }
    }
    ranges::sort(e);
    e.push_back({});

    auto get = [&](double x, int i) {
        if (sumLen[i] == 0) {
            return 1. / n[i];
        }
        return x / sumLen[i];
    };

    double ans = 0;
    int cnt[2] {};
    double sum[2] {}, poss[2] {};

    for (int i = 0; i < 2 * (n[0] + n[1]); i++) {
        auto [x1, t, j] = e[i];
        auto [x2, _, __] = e[i + 1];

        cnt[t] += j;
        double mid = double(x1 + x2) / 2;
        int len = x2 - x1;

        double cur[2] {get(len, 0), get(len, 1)};

        if (cnt[0] and cnt[1]) {
            ans += 1. / 3 * len * cur[0] * cur[1];
        }
        for (int i = 0; i < 2; i++) {
            if (cnt[i]) {
                ans += cur[i] * (poss[!i] * mid - sum[!i]);
            }
        }
        for (int i = 0; i < 2; i++) {
            if (cnt[i]) {
                sum[i] += cur[i] * mid;
                poss[i] += cur[i];
            }
        }
    }

    cout << fixed << setprecision(15) << ans << "\n";

    return 0;
}
