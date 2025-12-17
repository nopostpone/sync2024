#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<i64> f(n + 1);
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + (s[i] == '1' ? 1 : -1);
    }
    ranges::sort(f);

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (f[i] - f[i - 1]) * i * (n - i + 1);
    }

    for (int i = 0; i < n; i++) {
        ans += i64(i + 1) * (n - i);
    }

    ans /= 2;
    cout << ans << "\n";
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