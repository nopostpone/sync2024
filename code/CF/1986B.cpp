#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 120;
constexpr int inf = 1e9 + 1;
int a[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= max(n, m); i++) {
        a[0][i] = -inf;
        a[i][0] = -inf;
        a[n + 1][i] = -inf;
        a[i][m + 1] = -inf;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] > max({a[i][j - 1], a[i - 1][j], a[i + 1][j], a[i][j + 1]})) {
                a[i][j] = max({a[i][j - 1], a[i - 1][j], a[i + 1][j], a[i][j + 1]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " \n"[j == m];
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}