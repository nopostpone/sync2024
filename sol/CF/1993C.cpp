#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    int lo = *max_element(a.begin(), a.end());
    int hi = lo + k;

    auto f = [&](int x, int id) {
        return ((x - a[id]) / k) & 1;
    };
    
    for (int i = 0; i < n; i++) {
        while (f(lo, i)) {
            lo++;
        }
        while (f(hi, i)) {
            hi--;
        }
        if (lo > hi) {
            cout << -1 << endl;
            return;
        }
    }
    cout << lo << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}