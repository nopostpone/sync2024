#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<ll> ppre(n + 1);
    for (int i = 1; i <= n; i++) {
        ppre[i] = ppre[i - 1] + pre[i];
    }

    vector<ll> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + ppre[n] - ppre[i - 1] - pre[i - 1] * (n - i + 1);
    }

    vector<ll> siz(n + 1);
    for (int i = 1; i <= n; i++) {
        siz[i] = siz[i - 1] + n - i + 1;
    }

    auto sum = [&](ll x) -> ll {
        int u = lower_bound(siz.begin() + 1, siz.end(), x) - siz.begin();
        u--;

        ll y = u + x - siz[u];

        ll res = f[u];
        res += ppre[y] - ppre[u] - pre[u] * (y - u);

        return res;
    };

    int q;
    cin >> q;

    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << sum(r) - sum(l - 1) << "\n";
    }

    return 0;
}