#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = -a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i] = -b[i];
    }

    map<int, int> f;
    for (int i = 0; i < n; i++) {
        if (f.lower_bound(a[i]) != f.end()) {
            continue;
        }
        f[a[i]] = i + 1;
    }

    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        auto it = f.lower_bound(b[i]);
        if (it == f.end()) {
            res[i] = -1;
        } else {
            res[i] = it->second;
        }
    }
    for (auto i : res) {
        cout << i << "\n";
    }
    
    return 0;
}