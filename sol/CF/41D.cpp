#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr void chmax(auto &x, auto y) {
    if (y > x) {
        x = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    k++;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    pair<int, int> f[n + 1][m][k];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                f[i][j][x] = {-1, -1};
            }
        }
    }
    for (int j = 0; j < m; j++) {
        f[n][j][0] = {0, -1};
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {

                for (int t : {j - 1, j + 1}) {
                    if (0 <= t and t < m) {
                        int v = f[i + 1][t][x].first;
                        if (v == -1) {
                            continue;
                        }
                        int nv = v + s[i][j] - '0';
                        
                        chmax(f[i][j][(x + s[i][j] - '0') % k], pair(nv, t));
                    }
                }
            }
        }
    }

    
    int ans = -1, p = -1;
    for (int j = 0; j < m; j++) {
        if (f[0][j][0].first > ans) {
            ans = f[0][j][0].first;
            p = j;
        }
    }
    cout << ans << "\n";

    if (ans != -1) {
        vector<int> seq{p};
        int sum = ans;

        for (int i = 1; i < n; i++) {
            int q = f[i - 1][p][sum % k].second;

            sum -= s[i - 1][p] - '0';

            seq.push_back(q);
            p = q;
        }

        reverse(seq.begin(), seq.end());
        cout << seq[0] + 1 << "\n";
        for (int i = 1; i < n; i++) {
            cout << (seq[i] > seq[i - 1] ? "R" : "L");
        }
        cout << endl;
    }

    return 0;
}