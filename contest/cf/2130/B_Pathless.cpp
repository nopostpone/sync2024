#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, s;
    cin >> n >> s;

    array<int, 3> c{};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }
    int ori = c[1] + 2 * c[2];
    if (ori == s) {
        cout << -1 << "\n";
        return;
    }
    int d = s - ori;
    if (d < 0) {
        for (int x = 0; x < 3; x++) {
            for (int i = 0; i < c[x]; i++) {
                cout << x << " ";
            }
        }
        cout << "\n";
        return;
    }
    if (d == 1) {
        for (int x : {0, 2, 1}) {
            for (int i = 0; i < c[x]; i++) {
                cout << x << " ";
            }
        }
        cout << "\n";
        return;
    }
    cout << -1 << "\n";
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