#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    array<int, 32> p{};
    for (int i = 0; i < 32; i++) {
        p[i] = (n >> i & 1);
    }

    for (int i = 0; i < 31; i++) {
        if (p[i] == 0 and p[i + 1] == 0) {
            if (i == 0) {
                cout << "NO\n";
                return;
            }
            if (p[i - 1] == 1) {
                p[i] = 1;
                p[i - 1] = -1;
            } else if (p[i - 1] == -1) {
                p[i] = -1;
                p[i - 1] = 1;
            }
        }
    }
    
    cout << "YES\n";
    i64 x = 0;
    for (int i = 0; i < 32; i++) {
        cout << p[i] << " \n"[i == 31];
        x += ((i64)p[i] << i);
    }
    assert(x == n);
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