#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = n; i > 0 and k > 0; i--) {
        int now;
        if (i == n) {
            k -= n;
            cnt++;
        } else {
            k -= i;
            cnt++;
            if (k <= 0)
                break;
            k -= i;
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}