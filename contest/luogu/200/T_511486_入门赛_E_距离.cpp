#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(n));
    multiset<int> s;
    for (int i = 0; i < n * n; i++) {
        s.insert(0);
    }

    while (m--) {
        int op, x, y, k;
        cin >> op >> x >> y >> k;
        x--, y--;
        s.extract(a[x][y]);
        a[x][y] = a[x][y] + (op == 1 ? 1 : -1) * k;
        s.insert(a[x][y]);
        cout << *s.rbegin() << endl;
        
    }

    return 0;
}