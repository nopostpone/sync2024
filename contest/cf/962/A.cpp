#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    if (n % 4 == 0) {
        cout << n / 4 << endl;
    } else {
        cout << n / 4 + 1 << endl;
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}