#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    map<int, int> f;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        f[a]++;
    }

    vector<int> b;
    for (auto [x, y] : f) {
        b.push_back(y);
    }
    ranges::sort(b, greater());
    int ans = 0;
    for (int i = 0; i < b.size(); i++) {
        ans = max(ans, (i + 1) * b[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}