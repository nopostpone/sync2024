#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    k--;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int g = 0;
    for (int i = 0; i < n; i++)
        g = std::gcd(g, a[i]);
    
    if (n == 1)
        cout << k + (k >= g) << endl;
    else if (1ll * (g - 1) * n <= k)    
        cout << n + k << endl;
    else 
        cout << k / (g - 1) + k % (g - 1) + 1 << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}