#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = n - k; i < n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 0; i < n - k; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}