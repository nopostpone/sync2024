#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n1, n2;
    cin >> n1 >> n2;

    string s, t;
    cin >> s >> t;

    if (n1 > n2) {
        swap(n1, n2);
        swap(s, t);
    }
    map<char, int> f;
    for (auto c : s) {
        f[c]--;
    }
    for (auto c : t) {
        f[c]++;
        if (f[c] == 0) {
            f.erase(c);
        }
    }

    int ans = 0;

    int m = n2 - n1;
    for (auto &[x, y] : f) {
        if (m > 1) {
            while (y >= 2 and m >= 2) {
                y -= 2;
                m -= 2;
            }
        } else if (m == 1) {
            
        } else {
            break;
        }
    }
    if (m == 1) {
        for (auto [x, y] : f) {
            if (y >= 1) {
                f[x]--;
                m--;
                break;
            }
        }
    }
    for (auto [x, y] : f) {
        if (y < 0) {
            ans -= y;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}