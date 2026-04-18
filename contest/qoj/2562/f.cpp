#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dir(n);
    for (int i = 0; i < n; i++) {
        dir[i] = a[t[i]] >= a[i] ? 1 : -1;
    }

    vector<int> ans(n, -1);
    auto dfs = [&](this auto &&self, int x) -> void {
        if (ans[x] != -1) {
            return;
        }
        int y = t[x];
        if (dir[x] == dir[y]) {
            self(y);
            ans[x] = ans[y] + std::abs(a[x] - a[y]) * 2;
        } else {
            int p = y;
            while (dir[x] != dir[p] and dir[x] * (a[p] - a[x]) > 0) {
                p = t[p];
            }
            if (dir[x] * (a[p] - a[x]) <= 0) {
                ans[x] = std::abs(a[x] - a[y]);
            } else {
                self(y);
                ans[x] = std::abs(a[x] - a[y]);
                if (ans[x] > ans[y]) {
                    ans[x] = 2 * ans[x] - ans[y];    
                }
            }
        }
    };
    for (int i = 0; i < n; i++) {
        dfs(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}