#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<int> res;

void solve() {
    int n, x;
    int ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            int a = i, b = j / i, X = (n - a * b) / (a + b), Y = x - a - b;
            ans += max(0, min(X, Y));
        }
    }
    res.push_back(ans);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    for (auto i : res)
        cout << i << endl;
    return 0;
}