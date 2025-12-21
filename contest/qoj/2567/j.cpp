#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k, b;
    cin >> n >> m >> k >> b;

    vector s(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = accumulate(s[i].begin(), s[i].end(), 0);
        if (sum >= k) {
            ans++;
            continue;
        }
        if (b == 0) {
            continue;
        }
        for (int j = 0; j < m; j++) {
            if (s[i][j] <= 0) {
                sum++;
            } else {
                sum--;
            }
        }
        if (sum >= k) {
            b--;
            ans++;
        }
    }
    cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}
/*
2
5 3 2 1
-3 0 3
2 -2 -1
1 1 1
0 0 0
-1 -1 -1
3 2 -1 1
-1 -2
-3 -3
1 -3

*/