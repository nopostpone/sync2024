#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    int res = 2 * (b & 1);
    cout << (a & 1 ? "NO" : a >= res ? "YES" : "NO") << endl;    
    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}