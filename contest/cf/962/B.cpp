#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string a[1005];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i += m) {
        for (int j = 0; j < n; j += m) {
            cout << a[i][j];
        }
        cout << "\n";
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