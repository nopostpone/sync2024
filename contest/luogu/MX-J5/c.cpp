#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector f(11, vector<int>(11));

void solve() {
    int a, b;
    cin >> a >> b;

    if (1ll * a * b > 0) {
        cout << min({std::abs(a), std::abs(b), std::abs(a - b)}) << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}