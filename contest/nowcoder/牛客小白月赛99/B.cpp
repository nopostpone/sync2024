#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    int cnt = 0;
    while (n) {
        n %= (n / 2 + 1);
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
        solve();
    return 0;
}