#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

constexpr double inf = 4e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    using pdd = pair<double, double>;
    vector<pdd> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector dis(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        auto [xi, yi] = a[i];
        for (int j = i + 1; j < n; j++) {
            auto [xj, yj] = a[j];
            double dx = xj - xi;
            double dy = yj - yi;
            dis[i][j] = dis[j][i] = std::sqrt(dx * dx + dy * dy);
        }
    }
    
    vector dp(1 << n, vector<double>(n, inf));
    for (int i = 0; i < n; i++) {
        auto [x, y] = a[i];
        dp[1 << i][i] = sqrt(x * x + y * y);
    }

    for (int S = 0; S < (1 << n); S++) {
        for (int v = 0; v < n; v++) {
            if ((S >> v) & 1) {
                for (int u = 0; u < n; u++) {
                    dp[S][v] = min(dp[S][v], dp[S - (1 << v)][u] + dis[u][v]);
                }
            }
        }
    }

    cout << fixed << setprecision(2);
    // 一定要想好是求最大还是最小= =
    cout << *min_element(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end()) << endl;

    return 0;
}