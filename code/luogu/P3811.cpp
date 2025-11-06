#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, p;
    cin >> n >> p;

    vector<int> inv(p);
    inv[1] = 1;
    for (int i = 2; i < p; i++) {
        inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
    }

    for (int i = 1; i <= n; i++) {
        cout << inv[i] << "\n";
    }
    
    return 0;
}