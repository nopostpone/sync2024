#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

std::mt19937_64 rng{std::chrono::steady_clock::now().time_since_epoch().count()};

vector<int> res;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> f(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ll x = rng();
        f[a] ^= x;
        f[b] ^= x;
    }
    for (int i = 1; i < n; i++) {
        f[i] ^= f[i - 1];
    }
    map<ll, int> cnt;
    int tmp = 0;
    for (auto i : f) {
        tmp = max(tmp, ++cnt[i]);
    }
    res.push_back(n - tmp);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    for (auto i : res)
        cout << i << endl;
    return 0;
}