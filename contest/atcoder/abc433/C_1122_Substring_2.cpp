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

    string s;
    cin >> s;

    const int n = s.size();

    vector<pair<int, int>> a;

    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n and s[j] == s[i]) {
            j++;
        }
        a.emplace_back(j - i, s[i] - '0');
    }

    i64 ans = 0;
    for (int i = 1; i < a.size(); i++) {
        auto [l1, t1] = a[i - 1];
        auto [l2, t2] = a[i];

        if (t2 != t1 + 1) {
            continue;
        }
        ans += min(l1, l2);
    }
    cout << ans << "\n";

    return 0;
}