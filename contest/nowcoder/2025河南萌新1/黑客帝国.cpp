#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n;
    cin >> n;

    vector a(n, vector<int>(n));
    int x = (n - 1) / 2;
    int y = (n - 1) / 2;

    int dir = 0;
    int cnt = 1;
    int cur = 1;
    while (true) {
        if (cur == n * n) {
            break;
        }
        if (dir == 0) {
            for (int i = 0; i < cnt and cur < n * n; i++) {
                y++;
                a[x][y] = cur++;
            }
        } else if (dir == 1) {
            for (int i = 0; i < cnt and cur < n * n; i++) {
                x++;
                a[x][y] = cur++;
            }
        } else if (dir == 2) {
            for (int i = 0; i < cnt and cur < n * n; i++) {
                y--;
                a[x][y] = cur++;
            }
        } else {
            for (int i = 0; i < cnt and cur < n * n; i++) {
                x--;
                a[x][y] = cur++;
            }
        }
        dir = (dir + 1) % 4;
        if (dir % 2 == 0) {
            cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
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