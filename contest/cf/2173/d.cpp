#include <bits/stdc++.h>
using namespace std;

constexpr int E = 30;
constexpr int inf = 1e9;

constexpr auto chmax(auto &x, auto y) {
    if (y > x) {
        x = y;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    {
        int end = 1 << (__lg(n) + 1);
        int dif = end - n;

        if (__builtin_popcount(dif) <= k) {
            cout << __builtin_popcount(n) - 1 + k << "\n";
            return;
        }
    }

    vector f(E + 1, vector<int>(k + 2, -inf)), g(f);
    
    ranges::fill(f[0], 0);
    for (int i = 0; i < E; i++) {
        for (int j = 0; j <= k; j++) {
            chmax(f[i + 1][j], f[i][j]);
            if (n >> i & 1) {
                chmax(g[i + 1][j + 1], f[i][j] + 1);
                chmax(g[i + 1][j], g[i][j] + 1);
            } else {
                chmax(f[i + 1][j], g[i][j]);
                chmax(g[i + 1][j + 1], g[i][j] + 1);
            }
        }
    }
    cout << max(f[E][k], g[E][k]) << "\n";
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

