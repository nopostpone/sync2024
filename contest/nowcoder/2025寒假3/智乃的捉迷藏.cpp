#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if (a + b + c < n) {
        cout << "No\n";
        return;
    }

    if (a + b + c == n) {
        cout << "Yes\n";
        return;
    }
    int x = a + b + c;

    cout << (n >= x - x / 2 ? "Yes" : "No") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}