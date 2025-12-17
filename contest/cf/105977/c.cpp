#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int x) {
        vector<int> na(n);
        for (int i = 0; i < n; i++) {
            na[i] = a[i] >= x;
        }

        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (int t = stk.size(); t >= 2 and stk[t - 1] == 0 and stk[t - 2] == 0) {
                stk.pop_back();
                stk.pop_back();
                stk.push_back(0);
            } else {
                stk.push_back(na[i]);
            }
        }

        int c1 = count(stk.begin(), stk.end(), 1);
        int c0 = (int)stk.size() - c1;

        return c1 > c0;
    };

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int x = (lo + hi + 1) / 2;
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

    return 0;
}

/*
6
1
1
3
1 2 2
5
1 3 4 5 2
7
1 2 3 5 6 7 4
9
9 9 8 2 4 4 3 5 3
9
4 4 9 2 9 5 8 3 3
*/