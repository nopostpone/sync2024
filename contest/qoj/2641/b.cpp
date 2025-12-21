#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector p(n, vector<int>(m));
    vector<int> cnt(n * m + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
            cnt[p[i][j]]++;
        }
    }

    int tot = count_if(cnt.begin() + 1, cnt.end(), [](int x) {
        return x;
    });

    vector<int> ord(n * m);
    ranges::iota(ord, 1);
    ranges::sort(ord, [&](int i, int j) {
        return cnt[i] > cnt[j];
    });

    int paint = n * m - cnt[0];
    i64 sum = 0;

    i64 ans = (i64)paint * a;
    for (int i = 0; i < tot; i++) {
        paint -= cnt[ord[i]];

        sum += (i64(i) * cnt[ord[i]] + cnt[0]) * b;
        ans = min(ans, (i64)paint * a + sum);
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
3
1 2 3 2
0 1
2 2 1 1
1 0
2 3
3 3 5 3
2 4 4
4 1 4
4 4 2
*/