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

    vector<ll> num(m), den(m);
    int L = 0, R = -1;
    for (auto [l, r, id] : q) {
        if (l == r) {
            num[id] = 0;
            den[id] = 1;
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
        num[id] = sum;
        den[id] = 1ll * (r - l + 1) * (r - l) / 2;
    }

    for (int i = 0; i < m; i++) {
        if (num[i] == 0) {
            den[i] = 1;
        } else {
            ll g = std::gcd(num[i], den[i]);
            num[i] /= g;
            den[i] /= g;
        }
        cout << num[i] << "/" << den[i] << "\n";
    }

    return 0;
}