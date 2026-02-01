#include <bits/stdc++.h>
using namespace std;

bool query(int u, int v) {
    cout << "? " << u + 1 << " " << v + 1 << endl;
    int x;
    cin >> x;

    return x;
}

void solve() {
    int n;
    cin >> n;

    vector<int> cond(n);
    iota(cond.begin(), cond.end(), 0);

    for (int t = 0; t < n - 1; t++) {
        int u = cond.back();
        cond.pop_back();
        int v = cond.back();
        cond.pop_back();
        if (query(u, v)) {
            cond.push_back(v);
        } else {
            cond.push_back(u);
        }
    }

    int y = cond[0];
    for (int x = 0; x < n; x++) {
        if (x == y) {
            continue;
        }
        if (query(y, x) or not query(x, y)) {
            cout << "! " << -1 << endl;
            return;
        }
    }

    cout << "! " << y + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}