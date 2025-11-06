#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lo = 0, hi = n / 2 + 1;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        for (int i = 0; i < m; i++) {
            if (a[i] * 2 > a[n - m + i]) {
                hi = m;
            }
        }
        if (hi != m) {
            lo = m + 1;
        }
    }
    cout << lo - 1 << "\n";

    return 0;
}