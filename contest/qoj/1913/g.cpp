#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    auto check = [&](i64 k) {
        vector<int> pos, neg;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                int lo = 0, hi = n;
                while(lo < hi){
                    int x = (lo + hi) / 2;
                    if (a[i] * c[x] + b[i] >= k) {
                        hi = x;
                    } else {
                        lo = x + 1;
                    }
                }
                pos.push_back(n - lo);
            } else if (a[i] < 0) {
                int lo = -1, hi = n - 1;
                while (lo < hi) {
                    int x = (lo + hi + 1) / 2;
                    if (a[i] * c[x] + b[i] >= k) {
                        lo = x;
                    } else {
                        hi = x - 1;
                    }
                }
                neg.push_back(lo + 1);
            } else {
                cnt += b[i] >= k;
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        for (int i = 0, j = 1; i < pos.size(); i++) {
            if (pos[i] >= j) {
                j++;
                cnt++;
            }
        }
        for (int i = 0, j = 1; i < neg.size(); i++) {
            if (neg[i] >= j) {
                j++;
                cnt++;
            }
        }
        return cnt >= (n + 1) / 2;
    };

    i64 lo = -2e18, hi = 2e18;
    hi += 2;
    lo -= 2;
    while (lo < hi) {
        i64 x = (lo + hi + 1) >> 1;
        if (check(x)) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    cout << lo << "\n";
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
5
0 5 -2 1 2
9 -4 0 10 5
-4 -1 4 -2 4
10
-6 3 1 0 6 -2 -4 3 0 10
22 65 11 1 -34 -1 -39 -28 25 24
10 9 1 -2 -5 8 -7 -10 -7 -7
1
101
48763
651
*/