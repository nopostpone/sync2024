#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i];
    
    const ll sum = pre.back();

    auto getid = [&](ll x) -> int {
        return x / n;
    };

    auto g = [&](ll l, ll r, ll id) {

        l = (l + id) % n;
        r = (r + id) % n;
        
        if (r >= l)
            return pre[r + 1] - pre[l];
        else
            return sum - pre[l] + pre[r + 1];
    };

    auto query = [&](ll s, ll e) {
        int sid = getid(s), eid = getid(e);
        ll res = 0;
        if (sid == eid) {
            return g(s, e, sid);
        }
        res += g(s, 1ll * (sid + 1) * n - 1, sid);
        res += g(1ll * eid * n, e, eid);
        res += sum * (eid - sid - 1);
        return res;
    };  

    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << query(l - 1, r - 1) << endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}