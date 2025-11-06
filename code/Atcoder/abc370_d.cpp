#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<set<int>> X(n), Y(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            X[i].insert(j);
            Y[j].insert(i);
        }
    }

    int q;
    cin >> q;

    int res = n * m;

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (X[x].contains(y)) {
            res--;
            X[x].erase(y);
            Y[y].erase(x);
        } else {
            auto it = X[x].lower_bound(y);
            if (it != X[x].begin()) {
                int b = *prev(it);  
                res--;
                X[x].erase(b);
                Y[b].erase(x);
            }
            if (it != X[x].end()) {
                int b = *it;
                res--;
                X[x].erase(b);
                Y[b].erase(x);
            }
            it = Y[y].lower_bound(x);
            if (it != Y[y].begin()) {
                int a = *prev(it);
                res--;
                Y[y].erase(a);
                X[a].erase(y);
            }
            if (it != Y[y].end()) {
                int a = *it;
                res--;
                Y[y].erase(a);
                X[a].erase(y);
            }
        }
    }
    cout << res << endl;
    
    return 0;
}