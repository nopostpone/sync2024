#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using p64 = pair<i64, i64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<i64> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    ranges::sort(x);

    priority_queue<p64> q;
    for (int i = 1; i < n; i++) {
        q.emplace(x[i] - x[i - 1], i);
    }

    i64 ans = x[n - 1] - x[0];
    for (int i = 0; i < m - 1; i++) {
        auto [w, v] = q.top();
        q.pop();

        ans -= w;
    }

    cout << ans << "\n";

    // auto check = [&](i64 s) {
    //     int cnt = 0;
    // };

    // i64 lo = 0, hi = x[n - 1] - x[0];
    // while (lo < hi) {
    //     i64 x = (lo + hi) / 2;

    // }

    return 0;
}