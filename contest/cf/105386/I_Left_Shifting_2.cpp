#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    string s;
    cin >> s;

    const int n = s.size();

    if (ranges::count(s, s[0]) == n) {
        cout << n / 2 << "\n";
        return;
    }

    vector<int> b;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n and s[j] == s[i]) {
            j++;
        }
        b.push_back(j - i);
    }
    if (s[0] == s[n - 1]) {
        b.front() += b.back();
        b.pop_back();
    }

    int ans = 0;
    bool flag = false;
    for (auto x : b) {
        ans += x / 2;
        if (x % 2 == 0) {
            flag = true;
        }
    }
    ans -= flag;
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