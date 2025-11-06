// 这道题题意有问题
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll cal(int l, int r) {
    return 1ll * (l + r) * (r - l + 1) / 2;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> a(m);
    for (int j : {0, 1}) {
        for (int i = 0; i < m; i++) {
            cin >> a[i][j];
        }
    }
    ranges::sort(a);

    ll ans = cal(1, n);
    for (auto [x, y] : a) {
        ans -= 1ll * x * y;
    }
    int g = 0;
    bool ok = true;
    for (int i = m - 1; ~i and ok; i--) {
        g += a[i][1];
        if (g > n - a[i][0] + 1) {
            ok = false;
        }
    }
    cout << (g == n and ok ? ans : -1);


    return 0;
}
