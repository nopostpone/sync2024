#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    i64 L, R;
    cin >> L >> R;

    for (int i = 60; i >= 0; i--) {
        i64 u = L >> i & 1;
        i64 v = R >> i & 1;
        if (u == v) {
            L -= u << i;
            R -= u << i;
        } else {
            cout << L << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

}

/*
4
17 20
0 63
38 40
998244353998244353 998244853998244853
*/