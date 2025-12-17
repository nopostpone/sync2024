#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 1e9;
    for (auto [w, d] : a) {
        ans = min(ans, d * 7 + w - 6);
    }
    cout << ans << endl;
    
    return 0;
}