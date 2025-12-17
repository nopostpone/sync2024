#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b += x;
    }

    if ((a + b) & 1)
        cout << (a + b) / 2 + 1;
    else
        cout << (a + b) / 2;
    
    return 0;
}