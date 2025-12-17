#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        s.insert(a);
    }

    int ans = 0;
    i64 cur = 0;

    while (true) {
        auto it = s.lower_bound(cur);
        if (it == s.end()) {
            break;
        }
        ans++;
        cur += *it;
        s.extract(it);
    }
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
/*
2
5
1 3 4 7 9
3
1 1 1
*/