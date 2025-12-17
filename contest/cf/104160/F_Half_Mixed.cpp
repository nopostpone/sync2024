#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    i64 N = i64(n) * (n + 1) / 2;
    i64 M = i64(m) * (m + 1) / 2;

    if (N % 2 == 1 and M % 2 == 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";

    bool rev = false;
    if (N % 2 == 1) {
        swap(n, m);
        swap(N, M);
        rev = true;
    }

    i64 d = (i64)n * (n - 1) / 2 - n;

    vector<int> s;
    for (int i = 0, j = n; i < n; i++) {
        if (d == 0) {
            break;
        }
        while ((i64)j * j - j > d) {
            j--;
        }
        d -= (i64)j * j - j;
        s.push_back(j);
    }

    vector<int> a;
    bool cur = 0;
    for (auto x : s) {
        for (int i = 0; i < x; i++) {
            a.push_back(cur);
        }
        cur ^= 1;
    }
    while (a.size() < n) {
        a.push_back(cur);
        cur ^= 1;
    }

    if (rev) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i] << " \n"[j == m - 1];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}