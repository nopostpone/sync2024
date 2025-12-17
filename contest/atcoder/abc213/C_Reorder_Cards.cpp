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

    int _, __;
    cin >> _ >> __;

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    auto vx = x, vy = y;
    ranges::sort(vx);
    ranges::sort(vy);
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int i = 0; i < n; i++) {
        x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
        y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
    }
    for (int i = 0; i < n; i++) {
        cout << x[i] + 1 << " " << y[i] + 1 << "\n";
    }

    return 0;
}