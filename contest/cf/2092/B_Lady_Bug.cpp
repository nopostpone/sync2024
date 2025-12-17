#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    array<int, 2> f{};
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            f[(i + 1) % 2]--;
        }
        if (b[i] == '0') {
            f[i % 2]++;
        }
    }
    cout << (f[0] >= 0 and f[1] >= 0 ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}