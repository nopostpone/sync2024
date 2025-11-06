#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
        cin >> a[i];
    }

    auto check = [&](int x) -> bool {
        vector<bool> b(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; i++) {
            b[i] = a[i] > x;
        }
        for (int i = 0; i < n - 1; i++) {
            if (b[n - 1 + i] == b[n + i]) {
                return b[n + i];
            }
            if (b[n - 1 - i] == b[n - 2 - i]) {
                return b[n - 2 - i];
            }
        }
        return b[0];
    };

    int lo = 1, hi = 2 * n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
    
    return 0;
}