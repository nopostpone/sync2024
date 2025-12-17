#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int N = 1 << 18;
constexpr int B = 1 << 9;

array<int, N> a;
array<i64, B> f;
array<pair<int, int>, B> tag, ntag;
array<pair<int, int>, B * 2> tem;

int get(int i) {
    int p = i / B;
    int j = i % B;

    auto [q, k] = tag[p];
    return a[q * B + (j ^ k)];
}
void pull(int p) {
    f[p] = accumulate(a.begin() + p * B,
                          a.begin() + (p + 1) * B, i64());
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int nb = (n + B - 1) / B;

    for (int i = 0; i < nb; i++) {
        tag[i] = pair(i, 0);
    }

    auto push = [&](this auto &&self, int p) -> void {
        int u = -1, v = -1;

        for (int i = 0; i < nb; i++) {
            if (i != p and tag[i].first == p) {
                u = i;
                v = tag[i].second;

                break;
            }
        }

        array<int, B> ori{};

        for (int i = p * B; i < (p + 1) * B; i++) {
            ori[i - p * B] = get(i);
        }
        auto [q, k] = tag[p];

        tag[p] = pair(p, 0);

        if (u != -1) {
            self(u);
            for (int i = 0; i < nb; i++) {
                if (i != p and tag[i].first == p) {
                    auto [q, k] = tag[i];
                    tag[i] = pair(u, k ^ v);
                }
            }
        }

        for (int i = p * B; i < (p + 1) * B; i++) {
            a[i] = ori[i - p * B];
        }
        f[p] = f[q];
    };

    for (int i = 0; i < nb; i++) {
        pull(i);
    }

    for (int _ = 0; _ < q; _++) {
        int o, l, r;
        cin >> o >> l >> r;

        int lb = l / B;
        int rb = (r - 1) / B;

        if (o == 1) {
            int k;
            cin >> k;

            if (lb == rb) {
                int tot = 0;
                for (int i = l; i < r; i++) {
                    tem[tot++] = pair(i, get(i ^ k));
                }
                push(lb);

                for (int i = 0; i < tot; i++) {
                    auto [p, v] = tem[i];
                    a[p] = v;
                }
                pull(lb);
            } else {
                int hi = k / B, lo = k % B;

                int tot = 0;

                for (int i = l; i < (lb + 1) * B; i++) {
                    tem[tot++] = pair(i, get(i ^ k));
                }
                for (int i = rb * B; i < r; i++) {
                    tem[tot++] = pair(i, get(i ^ k));
                }
                for (int i = 0; i < nb; i++) {
                    if (lb < i and i < rb) {
                        int j = i ^ hi;
                        auto [q, k] = tag[j];

                        ntag[i] = pair(q, k ^ lo);
                    } else {
                        ntag[i] = tag[i];
                    }
                }
                for (int i = 0; i < nb; i++) {
                    tag[i] = ntag[i];
                }

                push(lb);
                push(rb);
                for (int i = 0; i < tot; i++) {
                    auto [p, v] = tem[i];
                    a[p] = v;
                }
                pull(lb);
                pull(rb);
            }

        } else {

            i64 ans = 0;
            if (lb == rb) {
                for (int i = l; i < r; i++) {
                    ans += get(i);
                }
            } else {
                for (int i = l; i < (lb + 1) * B; i++) {
                    ans += get(i);
                }
                for (int i = rb * B; i < r; i++) {
                    ans += get(i);
                }

                for (int i = lb + 1; i < rb; i++) {
                    ans += f[tag[i].first];
                }
            }

            cout << ans << "\n";
        }
    }

    fill(a.begin(), a.begin() + n, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}