#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> d(n);
    int m = 1;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        m *= d[i];
    }

    vector<i64> ans(m / d[x]);

    // 坐标 -> 状态数

    for (int i = 0; i < m; i++) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            if (i != x) {
                s = s * d[i] + p;
            }
        }
        int val;
        cin >> val;

        ans[s] += val;
    }

    // 状态数 -> 坐标
    vector<int> b(n);
    auto nxt = [&]() {
        int t = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i == x) {
                continue;
            }
            b[i] += t;
            t = 0;
            if (b[i] == d[i]) {
                b[i] = 0;
                t = 1;
            }
        }
    };

    for (int s = 0; s < m / d[x]; s++) {
        for (int i = 0; i < n; i++) {
            if (i == x) {
                continue;
            }
            cout << b[i] << " ";
        }
        cout << ans[s] << "\n";
        nxt();
    }

    return 0;
}