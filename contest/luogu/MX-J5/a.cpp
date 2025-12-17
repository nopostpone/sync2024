#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    ll x = 1;
    for (int i = 1; i <= n; i++) {
        x *= i;
    }

    cout << (x % (n + 1) == 0 ? "YES" : "NO") << endl;
    
    return 0;
}