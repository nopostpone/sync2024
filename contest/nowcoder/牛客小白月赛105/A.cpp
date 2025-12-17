#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (a * b < c * d ? "lz" : "gzy") << endl;
    
    return 0;
}