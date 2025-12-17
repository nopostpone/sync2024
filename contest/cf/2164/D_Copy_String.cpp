#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

void solve() {
    int n, km;
    cin >> n >> km;

    string s, t;
    cin >> s >> t;

    vector<int> d(n, -1);
    for (int i = n - 1, j = n - 1; i >= 0 and j >= 0; i = min(i, j)) {
        if (s[i] == t[j]) {
            d[j] = j - i;
            j--;
        } else {
            i--;
        }
    }

    int k = ranges::max(d);
    if (k > km or ranges::count(d, -1) > 0) {
        cout << -1 << "\n";
        return;
    }

    cout << k << "\n";
    for (int j = k; j; j--) {
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] >= j) {
                s[i - j + 1] = s[i - j];
            }
        }
        cout << s << "\n";
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