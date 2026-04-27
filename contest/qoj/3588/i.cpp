#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

vector<array<int, 6>> vec;

array<int, 12> ans[100];

int transform(int x) {
    if (x == 6) {
        x = 9;
    } else if (x == 9) {
        x = 6;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;

    if (ans[n][0] == -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (int i = 0; i < 12; i++) {
            cout << ans[n][i] << " \n"[i == 11];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 100; i++) {
        ans[i][0] = -1;
    }
    array<int, 6> a {};
    [&](this auto &&self, int p) {
        if (p == 6) {
            vec.emplace_back(a);
            return;
        }
        int base = p == 0 ? -1 : a[p - 1];
        for (int i = base + 1; i < 9; i++) {
            a[p] = i;
            self(p + 1);
        }
    } (0);

    for (auto a : vec) {
        for (auto b : vec) {
            array<bool, 100> vis {};
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    vis[a[i] * 10 + b[j]] = vis[b[j] * 10 + a[i]] = true;
                    a[i] = transform(a[i]);
                    b[j] = transform(b[j]);
                    vis[a[i] * 10 + b[j]] = vis[b[j] * 10 + a[i]] = true;
                    a[i] = transform(a[i]);
                    b[j] = transform(b[j]);
                }
            }
            int mex = 1;
            while (vis[mex]) {
                mex++;
            }
            if (ans[mex][0] == -1) {
                for (int i = 0; i < 6; i++) {
                    ans[mex][i] = a[i];
                }
                for (int i = 0; i < 6; i++) {
                    ans[mex][i + 6] = b[i];
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}