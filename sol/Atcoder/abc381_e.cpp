#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector pre(n + 1, vector<int>(2));
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '/') {
            pos.push_back(i + 1);
        }
        for (int j : {0, 1}) {
            pre[i + 1][j] = pre[i][j] + ((j == 0 and s[i] == '1') or (j == 1 and s[i] == '2'));
        }
    }

    auto check = [&](int l, int r, int x) {
        int u = pre[x][0] - pre[l - 1][0];
        int v = pre[r][1] - pre[x][1];
        return u < v;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;

        int lo = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        int hi = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
        hi--;

        if (lo > hi) {
            cout << 0 << "\n";
            continue;
        }

        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (check(l, r, pos[m])) {
                lo = m + 1;
            } else {
                hi = m;
            }
        }

        int ans = pre[r][1] - pre[pos[lo]][1];
        if (lo > 0) {
            lo--;
            ans = max(ans, pre[pos[lo]][0] - pre[l - 1][0]);
        }
        cout << 2 * ans + 1 << "\n";
    }

    return 0;
}