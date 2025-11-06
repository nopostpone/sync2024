#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    ll m;
    cin >> n >> m;

    vector<int> K(n), C(n);
    for (int i = 0; i < n; i++) {
        cin >> K[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += K[i] * C[i];
    }
    
    vector<ll> dp(sum + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j; j--) {
            for (int k = 1; k <= K[i]; k++) {
                if (j >= k * C[i]) {
                    dp[j] = max(dp[j], dp[j - k * C[i]] * k);
                }
            }
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (dp[i] >= m) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}