#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    auto get = [&](int i, int j) {
        i64 dx = abs(x[i] - x[j]);
        i64 dy = abs(y[i] - y[j]);
        double dis1 = dx + dy;
        double dis2 = sqrt(dx * dx + dy * dy);

        return dis1 / dis2;
    };

    vector<int> ord(n);
    ranges::iota(ord, 0);
    double ans = 0;
    {
        ranges::sort(ord, 
            [&](int i, int j) {
                return x[i] + y[i] < x[j] + y[j];
            });
        for (int i = 1; i < n; i++) {
            int u = ord[i - 1];
            int v = ord[i];

            ans = max(ans, get(u, v));
        }
    }
    {
        ranges::sort(ord, 
            [&](int i, int j) {
                return x[i] - y[i] < x[j] - y[j];
            });
        for (int i = 1; i < n; i++) {
            int u = ord[i - 1];
            int v = ord[i];

            ans = max(ans, get(u, v));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(20);
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
}

/*
2
2
0 0
0 1
3
1 1
2 3
5 8
*/