#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector A(n + 1, vector<int>(64));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) {
            A[i + 1][j] = A[i][j] + (a[i] >> j) & 1; 
        }
    }
    
    
    return 0;
}