#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

inline int lcm(int a, int b) { return a / __gcd(a, b) * b; }

void solve() {
    int x, y;
    cin >> x >> y;

    if (x == y) {
        cout << 0 << endl;
        return;
    }
    if (x > y) {
        swap(x, y);
    }

    if (y % x == 0) {
        cout << y << endl;
        return;
    }
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}