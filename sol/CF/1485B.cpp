#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int k;
vector<int> a, b;
vector<ll> res, pre;
ll tmp;

void solve() {
    int n, q, l, r;
    cin >> n >> q >> k;
    a.resize(n + 2, 0);
	b.resize(n + 2, 0);
	pre.resize(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i + 1] - a[i - 1] - 2;
    }
    while (q--) {
        cin >> l >> r;
        tmp = a[l + 1] - 2;
        tmp += k - a[r - 1] - 1;
        tmp += pre[r - 1] - pre[l];
        res.push_back(tmp);
    }
    for (auto i : res) {
        cout << i << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}