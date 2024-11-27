// 莫队板子
// 24.11.28 upd 更简洁

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    // q -> {l, r, id}
    vector<array<int, 3>> q(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> q[i][j];
        }
        q[i][0]--;
        q[i][1]--;
        q[i][2] = i;
    }

    const int len = sqrt(n);
    sort(q.begin(), q.end(), [&len](auto x, auto y) {
        if (x[0] / len == y[0] / len) {
            if ((x[0] / len) % 2 == 1) {
                return x[1] > y[1];
            } else {
                return x[1] < y[1];
            }
        }
        return x[0] < y[0];
    });

    ll sum = 0;
    vector<int> cnt(n);

    vector<ll> ans1(m), ans2(m);
    int L = 0, R = -1;
    for (auto [l, r, id] : q) {
        if (l == r) {
            ans1[id] = 0;
            ans2[id] = 1;
            continue;
        }
        while (L > l) {
            L--;
            assert(0 <= L and L < n);
            sum += cnt[a[L]];
            cnt[a[L]]++;
        }
        while (R < r) {
            R++;
            assert(0 <= R and R < n);
            sum += cnt[a[R]];
            cnt[a[R]]++;
        }
        while (L < l) {
            cnt[a[L]]--;
            sum -= cnt[a[L]];
            L++;
            assert(0 <= L and L < n);
        }
        while (R > r) {
            cnt[a[R]]--;
            sum -= cnt[a[R]];
            R--;
            assert(0 <= R and R < n);
        }
        ans1[id] = sum;
        ans2[id] = 1ll * (r - l + 1) * (r - l) / 2;
    }

    for (int i = 0; i < m; i++) {
        if (ans1[i] == 0) {
            ans2[i] = 1;
        } else {
            ll g = std::gcd(ans1[i], ans2[i]);
            ans1[i] /= g;
            ans2[i] /= g;
        }
        cout << ans1[i] << "/" << ans2[i] << "\n";
    }

    return 0;
}