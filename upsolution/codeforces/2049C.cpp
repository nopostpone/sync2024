#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;

#define nxt(x) (x + 1) % n
#define prv(x) (x - 1 + n) % n

    vector<int> a(n);

    if (y == prv(x) or y == nxt(x)) {
        for (int i = nxt(x); i != x; i = nxt(i)) {
            a[i] = a[prv(i)] ^ 1;
        }
        if (n % 2 == 1) {
            a[x] = 2;
        } else {
            a[x] = 0;
        }
    } else {
        for (int i = nxt(x); i != y; i = nxt(i)) {
            a[i] = a[prv(i)] ^ 1;
        }
        for (int i = prv(x); i != y; i = prv(i)) {
            a[i] = a[nxt(i)] ^ 1;
        }
        if (a[prv(y)] == a[nxt(y)]) {
            a[y] = a[prv(y)] ^ 1;
        } else {
            a[y] = 2;
        }
        for (int i = 0; i < 3; i++) {
            if (i != a[y] and i != a[prv(x)] and i != a[nxt(x)]) {
                a[x] = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}