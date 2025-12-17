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

    i64 ans = 0;
    int lst = 0;
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 and s[i - 1] == '2') {
            v = lst;
        }
        int x = s[i] - '0';
        if (x == 0) {
            v += 10;
        } else if (x == 1) {
            v -= 5;
        } else {
            lst = v;
            v -= 10;
        }
        v = max(0, v);
        ans += v;
    }
    cout << ans << "\n";

    return 0;
}