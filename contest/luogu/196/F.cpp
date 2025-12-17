#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector a(m + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x].push_back(i + 1);
    }
    for (int i = 0; i < n / m; i++) {
        for (int j = 1; j <= m ;j++) {
            cout << a[j][i] << endl;
        }
    }
    
    
    return 0;
}