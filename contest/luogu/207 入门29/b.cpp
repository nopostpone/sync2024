#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    bool u[3];
    u[0] = a + b >= k;
    u[1] = c + a >= k;
    u[2] = b + c >= k;

    for (auto i : u) {
        cout << (i ? "Yes" : "No") << "\n";
    }
    
    return 0;
}