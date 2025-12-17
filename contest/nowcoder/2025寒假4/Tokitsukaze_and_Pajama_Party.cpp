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

    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 8) == "uwawauwa") {
            a.push_back(i);
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'u') {
            int x = upper_bound(a.begin(), a.end(), i + 1) - a.begin();
            x = a.size() - x;
            ans += x;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}