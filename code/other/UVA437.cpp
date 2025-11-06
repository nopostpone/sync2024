// https://vjudge.net/problem/UVA-437
// vjudge 交 uva 只能选 c++11，难崩
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void answer(int a, ll b) {
    cout << "Case " << a << ": maximum height = " << b << endl;
}

void solve(int T) {
    int n;
    cin >> n;
    if (!n) {
        exit(0);
    }

    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];
    
    vector<vector<int>> dp(n, vector<int>(3, -1));

    function<int(int, int)> f = [&](int c, int rot){
        if (dp[c][rot] != -1) {
            return dp[c][rot];
        }
        dp[c][rot] = 0;
        int b1, b2;
        if (rot == 0) {
            b1 = x[c], b2 = y[c];
        } else if (rot == 1) {
            b1 = y[c], b2 = z[c];
        } else {
            b1 = x[c], b2 = z[c];
        }
        
        for (int i = 0; i < n; i++) {
            if ((x[i] < b1 and y[i] < b2) or (y[i] < b1 and x[i] < b2)) {
                dp[c][rot] = max(dp[c][rot], f(i, 0) + z[i]);
            }
            if ((y[i] < b1 and z[i] < b2) or (z[i] < b1 and y[i] < b2)) {
                dp[c][rot] = max(dp[c][rot], f(i, 1) + x[i]);
            }
            if ((x[i] < b1 and z[i] < b2) or (z[i] < b1 and x[i] < b2)) {
                dp[c][rot] = max(dp[c][rot], f(i, 2) + y[i]);
            }
        }

        return dp[c][rot];
    };

    int r = -1;
    for (int i = 0; i < n; i++) {
        r = max(r, f(i, 0) + z[i]);
        r = max(r, f(i, 1) + x[i]);
        r = max(r, f(i, 2) + y[i]);
    }
    answer(T, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 0;
    while (true) {
        solve(++T);
    }
    return 0;
}