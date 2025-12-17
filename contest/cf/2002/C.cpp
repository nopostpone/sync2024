#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

ll dis(int x1, int y1, int x2, int y2) {
    return (1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2));
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    ll d = dis(xs, ys, xt, yt);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (dis(x[i], y[i], xt, yt) <= d) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cerr << fixed << setprecision(10);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}