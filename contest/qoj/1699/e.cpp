// ref : jiangly https://qoj.ac/submission/767344
#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int K = 40;

constexpr string S = "ba";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    cin >> t;

    if (t.size() == 1) {
        cout << 1 << "\n";
        return 0;
    }

    const int n = t.size();

    vector fl(K, vector<array<int, 2>>(n + 1));
    vector fr(K, vector<array<int, 2>>(n + 1));

    for (int k = 0; k < K; k++) {
        fl[k][0] = {};
        for (int i = 1; i <= n; i++) {
            if (k < 2) {
                if (t[i - 1] == S[k]) {
                    fl[k][i] = {i - 1, 1};
                } else {
                    fl[k][i] = {i, 1};
                }
            } else {
                auto [a, b] = fl[k - 2][i];
                auto [c, d] = fl[k - 1][a];
                fl[k][i] = {c, b + d};
            }
        }
    }

    for (int k = 0; k < K; k++) {
        fr[k][n] = {n, 0};
        for (int i = n - 1; i >= 0; i--) {
            if (k < 2) {
                if (t[i] == S[k]) {
                    fr[k][i] = {i + 1, 1};
                } else {
                    fr[k][i] = {i, 1};
                }
            } else {
                auto [a, b] = fr[k - 1][i];
                auto [c, d] = fr[k - 2][a];
                fr[k][i] = {c, b + d};
            }
        }
    }

    int ans = 1e9;
    for (int k = 2; k < K; k++) {
        for (int i = 0; i <= n; i++) {
            auto [a, b] = fl[k - 1][i];
            auto [c, d] = fr[k - 2][i];
            if (a == 0 and c == n) {
                ans = min(ans, b + d);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}

/*
aabbaab
*/
