#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int P = 998244353;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater());
    int p0 = find(p.begin(), p.end(), 0) - p.begin();

    int ans = *max_element(p.begin(), p.end());

    int ed = 0;
    int rest = n;
    while (rest >= k) {
        if (ed + k - 1 >= p0) {
            break;
        }
        rest -= k - 1;
        ed += k - 1;
    }

    int cur = 1;
    for (int i = 0; i <= ed; i++) {
        cur = i64(cur) * p[i] % P;
        ans = cur;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
}

/*
3
8 3
44 5 2018 8 8 2024 8 28
5 4
4 5 5 1 0
5 2
0 0 0 0 0
*/