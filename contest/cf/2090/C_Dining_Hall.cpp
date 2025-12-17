#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int dis(int u, int v, int i) {
    int x = 3 * u + 1;
    int y = 3 * v + 1;
    if (i == 0) {
        return x + y - 1;
    } else if (i == 3) {
        return x + y + 3;
    } else {
        return x + y;
    }
}
constexpr array<int, 2> seats(int u, int v, int i) {
    int x = 3 * u + 1;
    int y = 3 * v + 1;
    if (i == 0) {
        return {x, y};
    } else if (i == 1) {
        return {x, y + 1};
    } else if (i == 2) {
        return {x + 1, y};
    } else {
        return {x + 1, y + 1};
    }
}

void solve() {
    int n;
    cin >> n;

    map<int, set<array<int, 2>>> f1, f2;
    int cnt = 0;

    for (int sum = 0; sum <= n; sum++) {
        if (cnt > n) {
            break;
        }
        for (int x = 0; sum - x >= 0; x++) {
            int y = sum - x;
            for (int i = 0; i < 4; i++) {
                int d = dis(x, y, i);
                auto arr = seats(x, y, i);
                if (i == 0) {
                    f2[d].insert(arr);
                }
                f1[d].insert(arr);
            }
            cnt++;
        }
    }
    
    for (int j = 0; j < n; j++) {
        int t;
        cin >> t;
        array<int, 2> ans{};
        if (t) {
            auto &[d, s] = *f1.begin();
            ans = *s.begin();
            f1[d].erase(ans);
            f2[d].erase(ans);
            if (f1[d].empty()) {
                f1.erase(d);
            }
            if (f2[d].empty()) {
                f2.erase(d);
            }
        } else {
            auto &[d, s] = *f2.begin();
            ans = *s.begin();
            f1[d].erase(ans);
            f2[d].erase(ans);
            if (f1[d].empty()) {
                f1.erase(d);
            }
            if (f2[d].empty()) {
                f2.erase(d);
            }
        }

        cout << ans[0] << " " << ans[1] << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}