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

    int sum = 0;

    vector<int> w(n), h(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i] >> b[i];
        sum += w[i];
    }

    vector<i64> dp(sum / 2 + 1);
    dp[0] = accumulate(b.begin(), b.end(), i64());

    for (int i = 0; i < n; i++) {
        for (int j = sum / 2; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + h[i] - b[i]);
        }
    }

    cout << ranges::max(dp) << "\n";

    return 0;
}