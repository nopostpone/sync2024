#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 and b == 0) {
        cout << (c ? -1 : 0) << "\n";
        return;
    }

    auto operate = [&](int t) {

    };
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