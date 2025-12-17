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

    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto b = a;
    for (int i = 0; i < n; i++) {
        b.push_back(a[i] - d);
    }

    i64 ans = 0;
    for (auto l : b) {
        int r = l + d;
        i64 res = 0;
        auto work = [&](int x) {
            x = max(x, l);
            x = min(x, r);
            return x;
        };
        for (int i = 0; i < n - 1; i++) {
            res += std::abs(work(a[i + 1]) - work(a[i]));
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";

    return 0;
}