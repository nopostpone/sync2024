#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int B = 315;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> p(n), pre(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pre[p[i] + 1]++;
    }
    for (int i = 0; i < n; i++) {
        pre[i + 1] += pre[i];
    }
    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int i, int j) {
        return p[i] < p[j];
    });

    const int nb = (n + B - 1) / B;
    vector f(nb, vector<i64>(nb + 1));
    for (int i = 0; i < n; i++) {
        f[ord[i] / B][i / B + 1]++;
    }
    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < nb; j++) {
            f[i][j + 1] += f[i][j];
        }
    }

    vector<i64> tag(nb), b(nb), a(n);

    i64 ans = 0;
    while (q--) {
        i64 o, l, r;
        cin >> o >> l >> r;
        l ^= ans;
        r ^= ans;

        l--;

        int lb = l / B;
        int rb = (r - 1) / B;
        if (o == 1) {
            i64 x;
            cin >> x;
            x ^= ans;
            if (lb == rb) {
                for (int j = l; j < r; j++) {
                    a[j] += x;
                }
            } else {
                for (int j = l; j < (lb + 1) * B; j++) {
                    a[j] += x;
                }
                for (int j = lb + 1; j < rb; j++) {
                    tag[j] += x;
                }
                for (int j = rb * B; j < r; j++) {
                    a[j] += x;
                }
            }
            l = pre[l];
            r = pre[r];
            if (l != r) {
                lb = l / B;
                rb = r / B;

                if (lb == rb) {
                    for (int j = l; j < r; j++) {
                        b[ord[j] / B] += x;
                    }
                } else {
                    for (int j = l; j < (lb + 1) * B; j++) {
                        b[ord[j] / B] += x;
                    }
                    for (int j = 0; j < nb; j++) {
                        b[j] += (f[j][rb] - f[j][lb + 1]) * x;
                    }
                    for (int j = rb * B; j < r; j++) {
                        b[ord[j] / B] += x;
                    }
                }
            }
        } else {
            ans = 0;
            if (lb == rb) {
                for (int j = l; j < r; j++) {
                    ans += a[p[j]] + tag[p[j] / B];
                }
            } else {
                for (int j = l; j < (lb + 1) * B; j++) {
                    ans += a[p[j]] + tag[p[j] / B];
                }
                for (int j = lb + 1; j < rb; j++) {
                    ans += b[j];
                }
                for (int j = rb * B; j < r; j++) {
                    ans += a[p[j]] + tag[p[j] / B];
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}