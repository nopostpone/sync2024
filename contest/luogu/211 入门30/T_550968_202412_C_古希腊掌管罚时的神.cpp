#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;


    ll ans{};
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            ans += 20;
        } else {
            ans += x;
        }
    }

    cout << ans << endl;
    
    return 0;
}