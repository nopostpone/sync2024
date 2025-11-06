#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // 比较典的区间问题
    
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ranges::sort(a);

    ll res = 0;
    for (int i : b) {
        res += n - (upper_bound(a.begin(), a.end(), i) - a.begin());
    }

    cout << 1ll * n * (n - 1) / 2 - res << endl;
    
    return 0;
}