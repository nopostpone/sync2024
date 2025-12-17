#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x[2][2], y[2][2], z[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> x[i][j] >> y[i][j] >> z[i][j];
            if (j % 2) {
                x[i][j]++;
                y[i][j]++;
                z[i][j]++;
            }
        }
    }

    auto work = [&](int a[2][2]) -> i64 {
        if (a[0][0] > a[1][0]) {
            swap(a[0], a[1]);
        }
        int res = min(a[1][1] - a[1][0], a[0][1] - a[1][0]);

        return max<i64>(res, 0);
    };

    cout << work(x) * work(y) * work(z) << "\n";

    return 0;
}