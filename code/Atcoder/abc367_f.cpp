#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};
constexpr int P = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<ll> hs(n);
    for (auto &i : hs) {
        i = rng() % P;
    }

    vector<ll> prea(n + 1), preb(n + 1);
    for (int i = 1; i <= n; i++) {
        prea[i] = prea[i - 1] + hs[a[i - 1]];
        preb[i] = preb[i - 1] + hs[b[i - 1]];
    }

    vector<bool> res;
    while (q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        res.push_back((prea[r] - prea[l - 1] == preb[R] - preb[L - 1]) and (r - l == R - L));
    }
    for (auto i : res) {
        cout << (i ? "Yes" : "No") << endl;
    }

    return 0;
}