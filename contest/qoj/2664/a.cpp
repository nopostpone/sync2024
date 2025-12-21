#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int a[1000][1000];

constexpr int safe(int x, int y) {
    if (x >= 0 and x < 1000 and y >= 0 and y < 1000) {
        return a[x][y];
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> o(n);

    array<int, 2> ans {};
    int t = 0;

    for (auto &[x, y] : o) {
        cin >> x >> y;
        x--;
        y--;

        a[x][y] = t;
        for (int i = x - 4; i < x + 1; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                cnt += safe(i + j, y) == t;
            }
            ans[t] += cnt == 5;
        }
        for (int i = y - 4; i < y + 1; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                cnt += safe(x, i + j) == t;
            }
            ans[t] += cnt == 5;
        }
        for (int i = x - 4; i < x + 1; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                cnt += safe(i + j, x + y - (i + j)) == t;
            }
            ans[t] += cnt == 5;
        }
        for (int i = x - 4; i < x + 1; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                cnt += safe(i + j, i + j - (x - y)) == t;
            }
            ans[t] += cnt == 5;
        }

        cout << ans[t] << " ";

        t ^= 1;
    }
    for (auto [x, y] : o) {
        a[x][y] = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 1000; i++) {
        fill(a[i], a[i] + 1000, -1);
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
1
14
1 1
2 1
1 2
2 3
1 3
2 5
1 4
2 7
1 5
2 4
1 6
2 2
1 7
2 6
*/
