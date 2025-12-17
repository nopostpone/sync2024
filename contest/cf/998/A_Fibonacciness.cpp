#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    array<int, 5> a;
    cin >> a[0] >> a[1] >> a[3] >> a[4];

    set<int> s;
    s.insert(a[0] + a[1]);
    s.insert(a[3] - a[1]);
    s.insert(a[4] - a[3]);

    cout << 3 - s.size() + 1 << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}