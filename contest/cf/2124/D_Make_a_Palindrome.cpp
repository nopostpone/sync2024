#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using p32 = pair<int, int>;

constexpr int inf = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    auto b = a;
    ranges::sort(b);

    vector<int> c;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[k - 1]) {
            c.push_back(a[i]);
        }
    }

    int rm = 0;
    int l = 0, r = c.size();
    while (l < r) {
        if (c[l] != c[r - 1]) {
            if (c[l] == b[k - 1]) {
                l++;
                rm++;
            } else {
                if (c[r - 1] == b[k - 1]) {
                    r--;
                    rm++;
                } else {
                    rm = inf;
                    break;
                }
            }
        } else {
            l++;
            r--;
        }
    }

    cout << ((int)c.size() - rm >= k - 1 ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}