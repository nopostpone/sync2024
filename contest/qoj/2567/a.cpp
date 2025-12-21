#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> d(n);
    int n0 = 0, n1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        d[i] *= 1000;
        if (d[i]) {
            n0++;
        }
        if (d[i] != 100 * 1000) {
            n1++;
        }
    }

    i64 sum = accumulate(d.begin(), d.end(), i64());
    i64 dif = sum - 100 * 1000;

    if (dif > 0) {
        if (dif > 500ll * n0) {
            cout << "No\n";
            return;
        }
        for (int i = 0; i < n and dif; i++) {
            if (d[i] == 0) {
                continue;
            }
            d[i] -= 500;
            dif -= 500;
        }
    } else {
        dif = -dif;
        for (int i = 0; i < n and dif; i++) {
            if (d[i] == 100 * 1000) {
                continue;
            }
            if (dif < 499) {
                d[i] += dif;
                dif = 0;
                break;
            }
            d[i] += 499;
            dif -= 499;
        }
        if (dif) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << d[i] << " \n"[i == n - 1];
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
    
    return 0;
}

/*
3
4
25 25 25 25
5
25 25 25 26 0
3
0 0 1

1
5
99 0 0 0 0
*/