#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    i64 n;
    int m, l;
    cin >> n >> m >> l;

    vector<pair<char, int>> A(m), B(l);
    for (auto &[s, a] : A) {
        cin >> s >> a;
    }
    for (auto &[t, b] : B) {
        cin >> t >> b;
    }

    i64 ans = 0;

    auto mov = [](i64 x, i64 y, char o, int len) {
        if (o == 'U') {
            x -= len;
        } else if (o == 'D') {
            x += len;
        } else if (o == 'L') {
            y -= len;
        } else {
            y += len;
        }
        return pair(x, y);
    };
    auto check = [](i64 x, i64 y, i64 u, i64 v) {
        if (x > y) {
            swap(x, y);
        }
        if (u > v) {
            swap(u, v);
        }
        auto L = max(u, x);
        auto R = min(v, y);
        if (L > R) {
            return false;
        }
        return (R - L) % 2 == 0;
    };

    int i = 0;
    for (auto [s, a] : A) {
        // cerr << s << " " << a << endl;
        while (i < l) {
            auto &[t, b] = B[i];

            if (b < a) {
                // cerr << "a" << endl;
                auto [nx1, ny1] = mov(x1, y1, s, b);
                auto [nx2, ny2] = mov(x2, y2, t, b);

                if (x1 == x2 and y1 == y2 and nx1 == nx2 and ny1 == ny2) {
                    ans += b;
                } else {
                    if (y1 == ny1 and x2 == nx2 and check(y1, y1, y2, ny2) and check(x2, x2, x1, nx1)) {
                        int U = abs(x1 - x2);
                        int V = abs(y1 - y2);
                        if (U == V) {
                            ans++;
                        }
                    }
                    if (y2 == ny2 and x1 == nx1 and check(y2, y2, y1, ny1) and check(x1, x1, x2, nx2)) {
                        int U = abs(x1 - x2);
                        int V = abs(y1 - y2);
                        if (U == V) {
                            ans++;
                        }
                    }
                    // cerr << x1 << " " << nx1 << " " << x2 << " " << nx2 << endl;
                    // cerr << (y1 == ny1 and y2 == ny2 and x1 == x2 and s != t) << endl;
                    if (y1 == ny1 and y2 == ny2 and y1 == y2 and s != t and check(x1, nx1, x2, nx2)) {
                        ans++;
                    }
                    if (x1 == nx1 and x2 == nx2 and x1 == x2 and s != t and check(y1, ny1, y2, ny2)) {
                        ans++;
                    }
                    cerr << ans << endl;

                    if (x1 == x2 and y1 == y2) {
                        ans--;
                    }
                }
                x1 = nx1;
                y1 = ny1;
                x2 = nx2;
                y2 = ny2;

                a -= b;
                i++;
            } else {
                // cerr << "b" << endl;
                auto [nx1, ny1] = mov(x1, y1, s, a);
                auto [nx2, ny2] = mov(x2, y2, t, a);

                if (x1 == x2 and y1 == y2 and nx1 == nx2 and ny1 == ny2) {
                    ans += a;
                } else {
                    // cerr << x1 << " " << x2 << " " << nx2 << " " << clamp(x1, x2, nx2) << endl;
                    if (y1 == ny1 and x2 == nx2 and check(y1, y1, y2, ny2) and check(x2, x2, x1, nx1)) {
                        int U = abs(x1 - x2);
                        int V = abs(y1 - y2);
                        if (U == V) {
                            ans++;
                        }
                    }
                    if (y2 == ny2 and x1 == nx1 and check(y2, y2, y1, ny1) and check(x1, x1, x2, nx2)) {
                        int U = abs(x1 - x2);
                        int V = abs(y1 - y2);
                        if (U == V) {
                            ans++;
                        }
                    }
                    if (y1 == ny1 and y2 == ny2 and y1 == y2 and s != t and check(x1, nx1, x2, nx2)) {
                        ans++;
                    }
                    if (x1 == nx1 and x2 == nx2 and x1 == x2 and s != t and check(y1, ny1, y2, ny2)) {
                        ans++;
                    }

                    if (x1 == x2 and y1 == y2) {
                        ans--;
                    }
                }
                x1 = nx1;
                y1 = ny1;
                x2 = nx2;
                y2 = ny2;
                b -= a;

                if (b == 0) {
                    i++;
                }
                break;
            }
        }
        // cerr << "ans = " << ans << endl;
        // cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    cout << ans << "\n";

    return 0;
}