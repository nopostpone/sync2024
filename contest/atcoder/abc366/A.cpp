#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, t, a;
    cin >> n >> t >> a;
    int x = n - t - a;

    if (t == a and x > 0) {
        cout << "No";
    } else if (t > a and a + x > t) {
        cout << "No";
    } else if (a > t and t + x > a) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    
    return 0;
}