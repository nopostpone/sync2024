#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= k;
        a = min(a, k - a);
        s.insert(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= k;
        a = min(a, k - a);
        s.extract(a);
    }
    cout << (s.empty() ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}