#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int power(int a, i64 b, int p) {
    int res = 1 % p;
    for (; b; b /= 2, a = (i64)a * a % p) {
        if (b & 1) {
            res = (i64)res * a % p;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, seed, maxv;
    cin >> n >> m >> seed >> maxv;

    auto rng = [&]() {
        auto ret = seed;
        seed = ((i64)seed * 7 + 13) % 1000000007;
        return ret;
    };

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (rng() % maxv) + 1;
    }

    map<int, i64> f;
    for (int i = 0; i < n; i++) {
        f[i] = a[i];
    }
    f[n] = -1;

    auto split = [&](int i) {
        auto it = f.upper_bound(i);
        assert(it != f.begin());
        it--;
        if (it->first != i) {
            f[i] = it->second;
        }
    };

    for (int i = 0; i < m; i++) {
        int op = rng() % 4 + 1;
        int l = rng() % n + 1;
        int r = rng() % n + 1;
        if (l > r) {
            swap(l, r);
        }
        l--;

        int x;
        if (op == 3) {
            x = rng() % (r - l);
        } else {
            x = (rng() % maxv) + 1;
        }

        split(l);
        split(r);

        if (op == 1) {
            for (auto it = f.find(l); it->first != r; it++) {
                it->second += x;
            }
        } else if (op == 2) {
            for (auto it = f.find(l); it->first != r; it = f.erase(it)) {
            }

            f[l] = x;
        } else if (op == 3) {
            vector<pair<i64, int>> v;
            for (auto it = f.find(l); it->first != r; it++) {
                int num = next(it)->first - it->first;
                i64 val = it->second;

                v.emplace_back(val, num);
            }

            ranges::sort(v);
            for (auto [val, num] : v) {
                if (x < num) {
                    cout << val << "\n";
                    break;
                }
                x -= num;
            }
        } else {
            int y = (rng() % maxv) + 1;

            int ans = 0;
            for (auto it = f.find(l); it->first != r; it++) {
                int num = next(it)->first - it->first;
                int val = it->second % y;

                int res = (i64)num * power(val, x, y) % y;
                ans = (ans + res) % y;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}