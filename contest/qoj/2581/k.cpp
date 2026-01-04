#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int dx[] {1, 1, 2, 2, -1, -1, -2, -2};
constexpr int dy[] {-2, 2, -1, 1, 2, -2, 1, -1};

void solve() {
    int xn, yn, xr, yr;
    cin >> xn >> yn >> xr >> yr;

    for (int i = 0; i < 8; i++) {
        
        int nx = xn + dx[i];
        int ny = yn + dy[i];
        
        if (nx < 1 or nx > 9 or ny < 1 or ny > 10) {
            continue;
        }
        if (dx[i] == 2 and xr == xn + 1 and yr == yn) {
            continue;
        }
        if (dx[i] == -2 and xr == xn - 1 and yr == yn) {
            continue;
        }
        if (dy[i] == 2 and yr == yn + 1 and xr == xn) {
            continue;
        }
        if (dy[i] == -2 and yr == yn - 1 and xr == xn) {
            continue;
        }

        if (nx == xr and ny == yr) {
            cout << "NO\n";
            return;
        }
        if (nx != xr and ny != yr) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
/*
2
1 5 2 5
1 1 2 3

1
1 1 2 2
*/