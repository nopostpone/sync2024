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

    string s;
    cin >> s;

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '1');
    }

    i64 ans = 0;
    for (int k = 1; k <= n; k++) {
        i64 res = 0;
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i += k) {
            int j = min(i + k, n);
            t1++;
            if (pre[j] - pre[i] == j - i or pre[j] - pre[i] == 0) {
                t2++;
            }
        }
        res = t1 + 1 - t2;
        ans ^= res;  
    }
    cout << ans << "\n";

    return 0;
}