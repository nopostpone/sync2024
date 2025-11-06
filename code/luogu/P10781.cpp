#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<double> a;
vector<double> res;

void solve() {
    int tt;
    cin >> tt;
    a[1] = 1, a[2] = a[3] = 1.5;
    while (tt--) {
        cin >> n >> k;
        res.push_back(double(k) * a[min(3, n)]);
    }
}

const int N = 1e6;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1;
    a.resize(N);
    while (_--)
        solve();
    cout << fixed << setprecision(1);
    for (auto i: res) {
        cout << i << '\n';
    }
    return 0;
}