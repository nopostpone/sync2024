#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class T>
istream &operator>>(istream &is, vector<T> &a) {
    for (auto &x : a) {
        is >> x;
    }
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> aa(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> aa[i][j];
        }
    }

    int sa = 8 * n, se = 12 * n, sc = n;
    for (auto [a, e, c] : aa) {
        sa -= a;
        se -= e;
        sc -= c;
    }
    int u = sa / 8;
    int v = se / 12;
    int w = sc;

    cout << min({u, v, w});

    return 0;
}