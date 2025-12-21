#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int P = 1'000'000'007;

int power(int a, i64 b) {
    int res = 1;
    for (; b; b /= 2, a = (i64)a * a % P) {
        if (b & 1) {
            res = (i64)res * a % P;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<array<int, 2>> dp(n + 1);
    dp[0][0] = dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
        
    }

    return 0;
}
/*
2 2
-1 -1
*/

/*
6 10
-1 -1 -1 -1 1 7
*/