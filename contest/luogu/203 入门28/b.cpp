#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, a, b;
    cin >> n >> a >> b;

    int l = a - b;
    int r = a + b;

    if (l < 0 and r > n) {
        cout << "No solution" << endl;
    } else if (l < 0 or l == r) {
        cout << r << endl;
    } else if (r > n) {
        cout << l << endl;
    } else {
        cout << l << " " << r << endl;
    }
    
    return 0;
}