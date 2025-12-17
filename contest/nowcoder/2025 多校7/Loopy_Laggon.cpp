#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr u64 P = 998244353;
constexpr u64 base = 461;

u64 Hash(const array<int, 100> &a) {
    u64 h = 0;
    for (int i = 0; i < 100; i++) {
        h = (1ll * h * base + a[i]);
    }
    return h;
}

#define ord(x, y) ((x) * 10 + (y))
#define ord2(x, y) ((x) * 4 + y)

array<int, 100> a{};
void rot(int x, int y, int type) {
    array<int, 16> oa{};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            oa[ord2(i, j)] = a[ord(i + x, j + y)];
        }
    }
    if (type == 1) {
        for (int i = 0; i < 3; i++) {
            a[ord(x + i, y + 3)] = oa[ord2(0, i)];
            a[ord(x + 3, y + 3 - i)] = oa[ord2(i, 3)];
            a[ord(x + 3 - i, y)] = oa[ord2(3, 3 - i)];
            a[ord(x, y + i)] = oa[ord2(3 - i, 0)];
        }
        a[ord(x + 1, y + 1)] = oa[ord2(2, 1)];
        a[ord(x + 1, y + 2)] = oa[ord2(1, 1)];
        a[ord(x + 2, y + 2)] = oa[ord2(1, 2)];
        a[ord(x + 2, y + 1)] = oa[ord2(2, 2)];
    } else {
        for (int i = 0; i < 3; i++) {
            a[ord(x, y + i)] = oa[ord2(i, 3)];
            a[ord(x + i, y + 3)] = oa[ord2(3, 3 - i)];
            a[ord(x + 3, y + 3 - i)] = oa[ord2(3 - i, 0)];
            a[ord(x + 3 - i, y)] = oa[ord2(0, i)];
        }
        a[ord(x + 2, y + 1)] = oa[ord2(1, 1)];
        a[ord(x + 1, y + 1)] = oa[ord2(1, 2)];
        a[ord(x + 1, y + 2)] = oa[ord2(2, 2)];
        a[ord(x + 2, y + 2)] = oa[ord2(2, 1)];
    }
};

unordered_set<u64> vis;
void dfs(int dep) {
    if (dep >= 3) {
        return;
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            rot(i, j, 1);
            auto h = Hash(a);
            if (not vis.contains(h)) {
                vis.insert(h);
                dfs(dep + 1);
            }
            rot(i, j, -1);
        }
    }
}

mt19937_64 rng{chrono::steady_clock::now().time_since_epoch().count()};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _, m, k, n;
    cin >> _ >> m >> k >> n;

    ranges::iota(a, 0);

    vis.insert(Hash(a));

    dfs(0);

    while (m--) {
        bool ok = false;
        for (int $ = 0; $ < k; $++) {
            for (int i = 0; i < 100; i++) {
                cin >> a[i];
                a[i]--;
            }
            auto h = Hash(a);
            
            if (ok) {
                break;
            }
            for (int i = 0; i < 7 and not ok; i++) {
                for (int j = 0; j < 7; j++) {
                    rot(i, j, 1);

                    for (int ii = i; ii < 7 and not ok; ii++) {
                        for (int jj = j; jj < 7; jj++) {
                            rot(ii, jj, 1);
                            if (vis.contains(Hash(a))) {
                                ok = true;
                            }

                            rot(ii, jj, -1);
                        }
                    }
                    if (vis.contains(Hash(a))) {
                        ok = true;
                    }
                    rot(i, j, -1);
                }
            }
        }
        if (ok) {
            cout << 0;
        } else {
            cout << rng() % 2;
        }
    }
    cout << "\n";

    return 0;
}