#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = -a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = -b[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '+') {
                a[i]++;
                b[j]++;
            }
        }
    }

    vector choose(n, vector<bool>(n));

    vector<int> pa(n), pb(n);
    ranges::iota(pa, 0);
    ranges::iota(pb, 0);

    ranges::sort(pa, [&](int i, int j) {
        return a[i] > a[j];
    });
    for (auto i : pa) {
        ranges::sort(pb, [&](int i, int j) {
            return b[i] > b[j];
        });

        for (auto j : pb) {
            if (a[i] > 0 and b[j] > 0) {
                a[i]--;
                b[j]--;
                choose[i][j] = true;
            }
        }
    }

    if (ranges::count(a, 0) == n and ranges::count(b, 0) == n) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '-') {
                    cout << choose[i][j];
                } else {
                    cout << !choose[i][j];
                }
            }
            cout << "\n";
        }
    } else {
        cout << "No\n";
    }
}

/*
3
+-+
-++
+-+
1 1 1
1 -1 3

3
---
-++
+++
-2 -1 0
-2 -1 0

3
+-+
-++
++-
1 0 2
2 2 -1
*/