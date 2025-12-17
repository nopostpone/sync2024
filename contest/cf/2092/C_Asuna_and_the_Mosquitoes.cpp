#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    i64 suma = accumulate(a.begin(), a.end(), 0ll);
    i64 sumb = accumulate(b.begin(), b.end(), 0ll);
    i64 ans;
    if (not a.empty() and (not b.empty())) {
        ans = suma + sumb - a.size() + 1;
    } else {
        ans = *ranges::max_element((a.empty() ? b : a));
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