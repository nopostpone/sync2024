#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    i64 tem = 1;
    i64 ans = 1;
    for (int i = 1; i <= m; i++) {
        tem *= n;
        ans += tem;
        if (ans > inf) {
            cout << "inf" << endl;
            break;
        }
    }
    if (ans <= inf) {

    cout << ans << "\n";
    }

    return 0;
}