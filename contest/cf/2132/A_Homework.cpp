#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    string a, b;

    cin >> n >> a >> m >> b;

    string op;
    cin >> op;

    for (int i = 0; i < m; i++) {
        if (op[i] == 'D') {
            a += b[i];
        } else {
            a = b[i] + a;
        }
    }
    cout << a << "\n";
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