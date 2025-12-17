// #include <bits/stdc++.h>
// using namespace std;

// using u8 = uint8_t;

// constexpr u8 inf = UINT8_MAX;

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         a[i]--;
//     }
//     vector dp(n, vector<u8>(n, inf));
//     for (int i = 0; i < n; i++) {
//         dp[i][i] = 0;
//     }

//     for (int i = n - 2; i >= 0; i--) {
//         auto ori = a;
//         vector<int> f(n, -1);
//         vector<int> cnt(n);

//         int counter = 0;
//         for (int j = i; j < n; j++) {
//             cnt[a[j]]++;
//             if (cnt[a[j]] == 2) {
//                 f[a[j]] = counter++;
//             }
//         }

//         for (int j = i; j < n; j++) {
//             a[j] = f[a[j]];
//         }

//         vector<int> s1(n), s2(n), s3(n);
//         for (int j = i; j < n; j++) {
//             s1[j] = 1 << a[j];

            
//         }


//         a = move(ori);
//     }

//     cout << (int)dp[0][n - 1] << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     for (cin >> T; T--;) {
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
        

    return 0;
}