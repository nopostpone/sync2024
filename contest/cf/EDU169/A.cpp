#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 2) {
        if (std::abs(a[1] - a[0]) <= 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        return;
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}