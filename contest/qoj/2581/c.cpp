#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    i64 n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Yes\n";
        cout << n / 2 << " " << n / 2 << "\n";
    } else {
        cout << "No\n";
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
3
1
6
7
*/