#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n), c(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    ranges::sort(p, [&](int i, int j) {
        if (a[i] - b[i] == a[j] - b[j]) {
            return a[i] < a[j];
        }
        return a[i] - b[i] < a[j] - b[j];
    });

    ll ans{};

    map<int, int> f;
    for (auto x : c) {
        if (x > 1e6) {
            int d = a[p[0]] - b[p[0]];
            int cnt = (x - a[p[0]]) / d;
            int cost = cnt * d;
            if (x - cost >= a[p[0]]) {
                cnt++;
                cost += d;
            }
            ans += 2 * cnt;
            x -= cost;
        }
        f[x]++;
    }

    int now{};
    for (int i = 1e6; i >= 0; i--) {
        if (not f.contains(i)) {
            continue;
        }
        while (now < n and a[p[now]] > i) {
            now++;
        }
        if (now == n) {
            break;
        }
        int j = p[now];

        int d = a[j] - b[j];
        int cnt = (i - a[j]) / d;
        int cost = cnt * d;
        if (i - cost >= a[j]) {
            cost += d;
            cnt++;
        }
        ans += 2ll * cnt * f[i];
        f[i - cost] += f[i];
    }

    cout << ans << "\n";

    return 0;
}
