#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr double g = 1;

void solve() {
    int n, H;
    cin >> n >> H;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    auto f = [H](int h) {
        double ans = sqrt(2. * h / g);
        ans *= sqrt(2. * g * (H - h));
        return ans;
    };
    vector<double> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = f(h[i]);
    }

    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return res[i] < res[j];
    });
    for (int i = 0; i < n; i++) {
        cout << ord[i] + 1 << " \n"[i == n - 1];
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}