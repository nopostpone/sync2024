#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;

    if (x < a) {
        a = 0;
    } else {
        a = 1;
    }
    if (x < c) {
        c = 0;
    } else {
        c = 1;
    }
    cout << a * b + c * d << endl;
    
    return 0;
}