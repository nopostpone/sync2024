#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int inf = 1e9;

void solve() {
    int n;
    cin >> n;

    map<int, int> f;
    int mn = inf;
    int mx = -inf;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        mn = min(a, mn);
        mx = max(a, mx);
        if (f.size() > 2) {
            cout << mn + mx << " ";
            continue;
        }
        f[a]++;
        if (f.size() == 2 and f[mn] == 1) {
            cout << 2 * mx << " ";
        } else {
            cout << mn + mx << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/*
3
6
1 1 4 5 1 4
5
1 2 3 4 5
5
1 2 2 1 2
*/