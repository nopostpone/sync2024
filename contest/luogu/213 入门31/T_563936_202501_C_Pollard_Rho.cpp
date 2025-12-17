#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)
        ->sync_with_stdio(false);

    int x, c, k;
    cin >> x >> c >> k;
    
    while (--k) {
        x = x * x + c;
        x %= 10000;
    }
    cout << x << endl;

    return 0;
}