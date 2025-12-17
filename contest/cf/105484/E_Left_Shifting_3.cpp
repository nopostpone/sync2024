#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr string tar = "nanjing";

auto calc(const string &s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += s.substr(i, 7) == tar;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    k = min(k, 7);
    int ans = calc(s);
    for (int i = 0; i < k; i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        ans = max(ans, calc(s));
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