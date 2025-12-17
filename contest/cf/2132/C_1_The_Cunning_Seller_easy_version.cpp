#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

vector<pair<int, i64>> f;

void solve() {
    int n;
    cin >> n;
    
    i64 ans = 0;
    for (auto [x, v] : f) {
        if (n < x) {
            continue;
        }
        i64 u = n / x;
        n -= u * x;

        ans += u * v;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 x = 0, num = 1;

    while (num <= 1e9) {
        i64 y = num * 3;
        i64 z = y / 9;
        f.emplace_back(num, y + z * x);

        x++;
        num *= 3;
    }
    reverse(f.begin(), f.end());

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}