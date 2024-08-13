#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a.begin(), a.end());

    vector w(n + 2, vector<int>(n + 2));
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            w[i][j] = w[i][j - 1] + a[j] - a[(i + j) / 2];
        }
    }
    vector dp(n + 1, vector<ll>(m + 1, 4e18));
    vector id(n + 2, vector<ll>(m + 1));
    dp[0][0] = 0;
    for (int j = 1; j <= m; j++) {
        id[n + 1][j] = n;
        for (int i = n; i; i--) {
            int mn = 2e9;
            int mnid;
            for (int k = id[i][j - 1]; k <= id[i + 1][j]; k++) {
                if (dp[k][j - 1] + w[k + 1][i] < mn) {
                    mn = dp[k][j - 1] + w[k + 1][i];
                    mnid = k;
                }
            }
            dp[i][j] = mn;
            id[i][j] = mnid;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}


// O (PV^2) 50pts

// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// using ll = long long;

// int main() {
//     cin.tie(nullptr)->sync_with_stdio(false);

//     int n, m;
//     cin >> n >> m;

//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
    
//     sort(a.begin(), a.end());

//     vector w(n + 1, vector<int>(n + 1));
//     for (int i = 1; i < n; i++) {
//         for (int j = i + 1; j <= n; j++) {
//             w[i][j] = w[i][j - 1] + a[j] - a[(i + j) / 2];
//         }
//     }

//     vector dp(n + 1, vector<ll>(m + 1, 4e18));
//     dp[0][0] = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             for (int k = 0; k < i; k++) {
//                 dp[i][j] = min(dp[i][j], dp[k][j - 1] + w[k + 1][i]);
//             }
//         }
//     }
//     cout << dp[n][m];

//     return 0;
// }