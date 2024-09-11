#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

// todo 355_d

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);

    auto cmp = [&](int x, int y) {
        return a[x] == a[y] ? b[x] < b[y] : a[x] < a[y];
    };

    sort(id.begin(), id.end(), cmp);

    ll res = 0;
    for (auto i : id) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (a[i] >= b[m]) {
                lo = m + 1;
            } else {
                hi = m;
            }
        }
        res += lo;
    }
    
    cout << 1ll * n * (n - 1) / 2 - res << endl;

    return 0;
}