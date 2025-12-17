#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t, d, t1, d1, t2, d2;
    cin >> t >> d >> t1 >> d1 >> t2 >> d2;

    t1 -= t, t2 -= t;

    bool ok1 = d <= d1;
    bool ok2 = d <= d2;

    int res = 0;
    if (ok1 and ok2) {
        res = min(t1, t2);
        res = max(res, 0);
    } else if (ok1) {
        res = t1;
        res = max(res, 0);
    } else if (ok2) {
        res = t2;
        res = max(res, 0);
    } else {
        res = -1;
    }
    cout << res << endl;
    
    return 0;
}