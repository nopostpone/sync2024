#include <bits/stdc++.h>
using namespace std;

vector<int> a[4];

map<int, int> f = {{12, 1}, {123, 2}, {1234, 3}};

void solve() {
    int n, j, k;
    cin >> n >> j >> k;

    j--;
    k--;

    int w = f[n];

    int x = a[w][j];
    int y = a[w][k];

    int ans = 0;

    for (int i = 0; i <= w; i++) {
        if ((x % 10) == (y % 10)) {
            ans++;
        }
        x /= 10;
        y /= 10;
    }

    cout << ans << "A" << w + 1 - ans << "B" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int n = 2; n <= 4; n++) {
        vector<int> p(n);
        ranges::iota(p, 1);

        do {
            int res = 0;
            for (auto x : p) {
                res = res * 10 + x;
            }
            a[n - 1].push_back(res);
        } while (next_permutation(p.begin(), p.end()));
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    };
}