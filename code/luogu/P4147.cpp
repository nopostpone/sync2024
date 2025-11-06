#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector s(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            s[i][j] = (x == 'F');
        }
    }

    vector f(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i + 1][j + 1] = (s[i][j] ? f[i][j + 1] : i + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = i - f[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> l(m + 1, 0), r(m + 1, m + 1);
        {
            vector<int> stk;
            for (int j = 1; j <= m; j++) {
                while (not stk.empty() and f[i][stk.back()] >= f[i][j]) {
                    stk.pop_back();
                }
                if (not stk.empty()) {
                    l[j] = stk.back();
                }
                stk.push_back(j);
            }
        }
        {
            vector<int> stk;
            for (int j = m; j >= 1; j--) {
                while (not stk.empty() and f[i][stk.back()] >= f[i][j]) {
                    stk.pop_back();
                }
                if (not stk.empty()) {
                    r[j] = stk.back();
                }
                stk.push_back(j);
            }
        }
        for (int j = 1; j <= m; j++) {
            ans = max(ans, f[i][j] * (r[j] - l[j] - 1));
        }
    }
    cout << 3 * ans << "\n";

    return 0;
}