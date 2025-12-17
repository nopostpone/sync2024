#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    const int m = 2 * n;

    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    vector<int> id;
    int mx = -1;
    for (int i = 0; i < m; i++) {
        if (p[i] > mx) {
            mx = p[i];
            id.push_back(i);
        }
    }
    id.push_back(m);

    vector<int> siz;
    for (int i = 1; i < id.size(); i++) {
        siz.push_back(id[i] - id[i - 1]);
    }

    vector<bool> dp(m + 1);
    dp[0] = true;
    for (auto i : siz) {
        for (int j = m; j >= i; j--) {
            dp[j] = dp[j] | dp[j - i];
        }
    }

    cout << (dp[n] ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    for (cin >> T; T--;) {
        solve();
    }

    return 0;
}