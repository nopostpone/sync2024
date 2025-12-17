#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t, a, b, c, d;
    cin >> t >> a >> b >> c >> d;

    int res = 0;
    if (t == 0) {
        res = a + b;
    } else {
        res = max(a - c, 0) + max(b - d, 0);
    }
    cout << res << endl;
    
    return 0;
}