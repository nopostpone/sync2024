#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << 1ll * b * y + 1ll * a * min(x, y) << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}