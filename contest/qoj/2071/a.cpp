#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128;

constexpr i64 P = i64(1e18) + 9;

constexpr i64 mul(i64 a, i64 b) {
    return i128(a) * b % P;
}
constexpr i64 norm(i64 x) {
    if (x >= P) {
        x -= P;
    }
    if (x < 0) {
        x += P;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<array<int, 20>> f(n + 1);
    for (int i = 0; i <= n; i++) {
        f[i][0] = n;
    }

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (not stk.empty() and a[stk.back()] <= a[i]) {
            f[stk.back()][0] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    vector<array<i64, 20>> g(n + 1);
    for (int i = 0; i <= n; i++) {
        g[i][0] = f[i][0] - i;
    }

    array<i64, 20> w {};
    w[0] = 1234567;
    for (int j = 0; j < 19; j++) {
        w[j + 1] = mul(w[j], w[j]);
        for (int i = 0; i <= n; i++) {
            f[i][j + 1] = f[f[i][j]][j];
            g[i][j + 1] = norm(mul(g[i][j], w[j]) + g[f[i][j]][j]);
        }
    }

    auto get = [&](int l, int r) {
        i64 res = 0;
        for (int j = 19; j >= 0; j--) {
            if (f[l][j] < r) {
                res = norm(mul(res, w[j]) + g[l][j]);
                l = f[l][j];
            }
        }
        return res;
    };

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--;
        l2--;
        
        cout << (get(l1, r1) == get(l2, r2) ? "Yes" : "No") << "\n";
    }
}

/*
10 6
3 1 4 1 5 9 2 6 5 3
1 3 3 5
1 5 6 10
1 1 9 9
1 9 1 9
1 3 6 8
5 8 7 10
*/